---
layout: post
title: Trabalho 1 - Pontos, Linhas e triângulos
---

  Como primeiro trabalho da disciplina de Introdução à Computação Gráfica, temos que desenvolver três partes do processo de rasterização:

1. Rasterização de pontos (função PutPixel)
2. Rasterização de linhas (função DrawLine)
3. Desenho das bordas de um triângulo (função DrawTriangle)
<!--more-->

  Estamos utilizando o framework criado pelo professor Christian Pagot. Esse framework simula a memória de vídeo através de um array que representa cada canal de cor de cada pixel. A nossa "tela" tem 512x512 pixels. Internamente, o framework usa esse array como dados de uma textura que é aplicada sobre um quadrilátero.

  Para gerar imagens, a primeira coisa que precisamos fazer é rasterizar pontos/pixels. Primeiro, criei uma estrutura de dados chamada Pixel:
  
  ```C++
  typedef struct{
    unsigned int x;
    unsigned int y;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
  } Pixel;
  ```
  Os dois primeiros campos da estrutura representam as coordenadas do pixel na tela. As outras representam o valor de cada canal de cor, com 8 bits por canal.
  
  Com isso, podemos agora criar a função PutPixel:
  
  ```C++
  void PutPixel(Pixel p)
  ```
  
  Na nossa "memória de vídeo", cada 4 bytes representam 1 pixel. Além disso, os pixels no array estão agrupados de linha em linha, ou seja, a cada 4 elementos do array, a coordenada X do pixel muda, mas a coordenada Y só muda a cada 2048 elementos (mais especificamente, a cada elemento múltiplo de 512 o Y muda).
  
  Por isso, para achar o índice do primeiro byte do pixel (x, y) que nós queremos desenhar, precisamos usar a seguinte fórmula:
  
  ```
  index = (WIDTH*y + x) * 4
  ```
  
  Onde WIDTH é a largura da tela em pixels, nesse caso, 512.
  
  Depois, é só colocar os valores dos campos r, g, b, a da estrutura em seus respectivos lugares
  
  ```
  FBptr[index] = r
  FBptr[index + 1] = g
  FBptr[index + 2] = b
  FBptr[index + 3] = a
  ```

  Agora, já podemos desenhar Pixels na tela. Exemplo: tornar todos os pixels da tela vermelhos usando laços de repetição e PutPixel:
  
  ![Pixels vermelhos](https://raw.githubusercontent.com/SanctusImmortalis/CGTrabalhos/master/docs/assets/2.png)


  Agora que temos pontos, podemos rasterizar linhas. Como linhas são apenas um conjunto de pontos, desenhar uma não parece ser difícil, mas há um problema: linhas matemáticas são contínuas, mas monitores são discretos. As telas de nossos computadores, bem como a memória de vídeo, são dividos em pixels, como já vimos no começo. Ou seja, é necessário criar uma aproximação das linhas matemáticas. Isso, no entanto, gera outro problema: como decidir qual pixel acender nos locais onde a linha não está exatamente em cima de um pixel?
  
  A solução mais utilizada apenas acende o pixel mais próximo da linha, ou seja, o pixel cujo centro está mais próximo daquele ponto na linha. Uma solução simples seria pegar os valores inteiros de X pelos quais a linha passa, e calcular o Y para cada X, e então arredondar os valores de Y resultantes para que eles também fiquem inteiros. Então, é só rasterizar esses pixels. No caso de dx>dy, b sendo o offset da reta em relação à reta x = y: 
  
  ```
  dx = x1 - x0
  dy = y1 - y0
  m = dy/dx
  x = x0
  while(x<x1)
    y = m*x0 + b
    PutPixel(x, Round(y))
    x += 1
  ```
  
  No entanto, esse algoritmo contém duas operações caríssimas: produto de ponto flutuante e arredondamento. Vimos em sala que é possível usar alguns truques matemáticos para gerar um algoritmo equivalente que utiliza apenas somas e comparações (dentro do loop. O custo de usar operações um pouco mais caras uma ou duas vezes fora do loop é negligível). Esse é o algoritmo de Bresenham, em C++:
  
  ```C++
  void DrawLine(Pixel p1, Pixel p2){
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int d = 2* dy - dx;
    int incr_e = 2 * dy;
    int incr_ne = 2 * (dy - dx);

    Pixel p = p1;
    PutPixel(p);
    while(p.x < p2.x){
      if (d<=0) {
        d += incr_e;
        p.x++;
      }else{
        d += incr_ne;
        p.x++;
        p.y++;
      }


      PutPixel(p);
  }
  ```
  
  Essa função em C resolve o problema... para um oitavo das linhas possíveis. Para qualquer linha cujo ângulo em relação ao eixo X seja 45°, ou com x1<x0 ou y1<y0, esse algoritmo é incapaz de nos dar o resultado certo. No entanto, adaptar esse algoritmo para os outros octantes é simples.
  
  Para os casos onde x1 < x0, é só definir dx como:
  ```
  dx = x0 - x1
  ```
  e decrementar o X no loop.
  
  De forma similar, quando y1 < y0:
  ```
  dy = y0 - y1
  ```
  e também decrementar o y.
  
  Quando o ângulo em relação ao eixo X for maior que 45°, isso significa que o valor de Y dos pixels muda mais rápido que o valor de X, ou seja, Dx < Dy. Então é só trocar todas as ocorrências de x e dx por y e dy, e vice-versa. Combinando essas alterações de diversas maneiras, é possível gerar todos os octantes:
  
<table style="width:100%">
  <tr>
    <th>Octante</th>
    <th>X</th>
    <th>Y</th>
    <th>Dx maior que Dy</th>
  </tr>
  <tr>
    <td>1</td>
    <td>+</td>
    <td>+</td>
    <td>Sim</td>
  </tr>
  <tr>
    <td>2</td>
    <td>+</td>
    <td>+</td>
    <td>Não</td>
  </tr>
  <tr>
    <td>3</td>
    <td>-</td>
    <td>+</td>
    <td>Não</td>
  </tr>
  <tr>
    <td>4</td>
    <td>-</td>
    <td>+</td>
    <td>Sim</td>
  </tr>
  <tr>
    <td>5</td>
    <td>-</td>
    <td>-</td>
    <td>Sim</td>
  </tr>
  <tr>
    <td>6</td>
    <td>-</td>
    <td>-</td>
    <td>Não</td>
  </tr>
  <tr>
    <td>7</td>
    <td>+</td>
    <td>-</td>
    <td>Não</td>
  </tr>
  <tr>
    <td>8</td>
    <td>+</td>
    <td>-</td>
    <td>Sim</td>
  </tr>
</table>

  Após isso, é só fazer a função DrawLine decidir em qual octante estamos desenhando, e chamar a variante correta do algoritmo de Bresenham.
  
  Com as linhas em si corretamente implementadas, precisamos fazer interpolação de cores. Quando definimos os pontos inicial e final, também definimos a cor de cada um deles. Quando esses pontos são rasterizado, devem ter essa cor. No entanto, como deveriamos colorir os pontos restantes? A resposta é interpolação linear. Cada ponto tem uma cor baseada na sua posição em relação às extremidades. Para implementar isso, calculamos a taxa de variação de cada canal de cor em relação a X (em relação a Y quando Dy > Dx):
  
  ```C++
  double dr = (p2.r - p1.r)/((double) dx);
  double dg = (p2.g - p1.g)/((double) dx);
  double db = (p2.b - p1.b)/((double) dx);
  double da = (p2.a - p1.a)/((double) dx);
  ```
  E então, durante o loop, incrementamos os valores de r, g, b, a do ponto por essas taxas de variação:
  
  ```C++
  r += dr;
  g += dg;
  b += db;
  a += da;
  p.r = (unsigned char)(r);
  p.g = (unsigned char)(g);
  p.b = (unsigned char)(b);
  p.a = (unsigned char)(a);
  ```
  
  E agora, podemos desenhar linhas em todos os octantes com interpolação de cores:
  
  ![Todas as linhas](https://raw.githubusercontent.com/SanctusImmortalis/CGTrabalhos/master/docs/assets/17.png)
  
  Finalmente, desenhar as bordas de um triângulo. Deve-se notar que rasterizar um triângulo também inclui preenchê-lo, o que não estamos fazendo aqui.
  
  Para desenhar as bordas de um triângulo precisamos apenas dar os três vértices do triângulo e desenhar linhas entre eles. É assim que se faz um triângulo com três pontos:
  
  ```C++
  void DrawTriangle(Pixel p1, Pixel p2, Pixel p3){
    DrawLine(p1, p2);
    DrawLine(p2, p3);
    DrawLine(p3, p1);
  }
  ```
  
  ![Triângulo vermelho](https://raw.githubusercontent.com/SanctusImmortalis/CGTrabalhos/master/docs/assets/13.png)
  
  ![Triângulo colorido](https://raw.githubusercontent.com/SanctusImmortalis/CGTrabalhos/master/docs/assets/15.png)
  
# Conclusão

  Com esse trabalho foi possível entender melhor o algoritmo de Bresenham visto em sala, e também como funciona o acesso à memória de vídeo. Também aprendi sobre interpolação de cores. A maior dificuldade foi fazer a interpolação, pois originalmente tentei fazer sem usar ponto flutuante, mas esse método se mostrou muito complicado e acabou gerando uma gambiarra. Ainda me pergunto, no entanto, se há um jeito mais eficiente de se calcular a interpolação.
