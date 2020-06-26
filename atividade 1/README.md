# Atividade 1

### Sobre a atividade
  Utilizando a framework disponibilizada pelo professor e utilizando de algoritimos de computação gráfica o objetivo era rasterizar pontos e linhas na tela.
  
### Funções
  * putPixel(): função que recebe três parametros, a coordenada x, y e uma cor.
    
    ![](images/putpixel.png)
  
  * Drawline(): função que recebe como parametro uma coordenada x inicial(xi), x final(xf), y inicial(yi), y final(yf) e uma cor. Através das coordenadas ligam-se os ponto para formar uma reta.
  
    ![](images/drawline.png)
  
### Problemas encontrados

  A framework disponibilizada tinha seu funcionamento limitado ao sistema operacional linux, não podendo ser executado no windows. Das tentativas:
  - Usar uma maquina virtual - falhou devido as configurações da máquina;
  - Fazer dual boot - falhou, me falta um pen drive ou um CD pra fazer boot;
  - Adaptar o codigo pra que funcionasse no windows - falhou;
    
  O código foi testado por um amigo em sua máquina que me repassou o comportamento do programa.
  
  ### Referências
  
* [Wikipedia](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#:~:text=Bresenham%27s%20line%20algorithm%20is%20a,straight%20line%20between%20two%20points)   ;
* Slides passado pelo professor.
