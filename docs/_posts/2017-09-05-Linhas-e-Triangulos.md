---
layout: default
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
