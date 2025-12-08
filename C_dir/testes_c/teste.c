#include <stdio.h>

/*
  Funções a serem implementadas:

  1. consumo_medio(float combustivel, float quilometros); (l, km) -> consumo medio de litro por km
  2. preco_forrar(float comprimento[2], float preco_metro); (m2, R$/m2) -> preço total 
  3. calcular_IMC(float peso, float altura); (kg, m) -> imc
  4. tempo_download(float arquivo, float bit_segundo); (b, b) -> tempo de download
  5. calcular_juros(float c, float j, int m); (capital, juros, meses) -> montante F

*/

float consumo_medio(float l, float km);
float preco_forrar(float c[2], float p);
float calcular_IMC(float kg, float h);
float tempo_download(long arquivo, float bits_s);
float calcular_montante(float c, float j, float m); // F = C * (1+j/100)^m

int main(){

  printf("l/mk: %.2f\n", consumo_medio(6, 55.7));

  float x[2] = {2.5, 5.6};
  printf("preço por m²: R$%.2f\n", preco_forrar(x, 10.99));

  printf("IMC: %.2f\n", calcular_IMC(80, 1.78));

  printf("Tempo necessário pro download: %fs\n", tempo_download(8096, 350.5));

  float capital = 1200;
  float taxa = 3.55;
  int meses = 8;

  printf("R$%.2f a uma taxa de %.2f%% durante %i meses renderá: R$%.2f\n", capital, taxa, meses, calcular_montante(capital, taxa, meses));

  return 0;
}

float consumo_medio(float l, float km){
  return l / km;
}

float preco_forrar(float c[2], float p){
  float comprimento = c[0];
  float largura = c[1];
  float m2 = largura * comprimento;

  return m2 * p;
}

float calcular_IMC(float kg, float h){
  return kg / (h * h);
}

float tempo_download(long arquivo, float bits_s){
  float rate = arquivo / bits_s;
  return rate;
}

float calcular_montante(float c, float j, float m){ // F = C * (1+j/100)^m
  float f = (1 + (j/100));

  for(int i = 0; i < m; i++){
    printf("Mês %i = %.2f\n", i, f);
    f *= f;
  }

  f *= c;

  return f-c;
}
