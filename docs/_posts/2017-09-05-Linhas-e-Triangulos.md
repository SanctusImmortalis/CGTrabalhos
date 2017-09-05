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
  
  No entanto, esse algoritmo contém duas operações caríssimas: produto de ponto flutuante e arredondamento.
