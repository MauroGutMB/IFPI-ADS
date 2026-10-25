import java.util.*;
import java.io.*;

public class App {

  void main() {

    ArrayList<String> lista = new ArrayList<>();
    BufferedWriter bw;

    boolean in = true;
    String opt;

    while (in) {
      menuElemento();
      opt = IO.readln(" -> ");
      int optInt = 0;

      try {
        optInt = Integer.parseInt(opt);
      } catch (Exception e) {
        System.out.println("Erro");
      }

      switch (optInt) {
        case 1: {
          String texto = IO.readln("Texto a ser inserido -> ");
          lista.add(texto);
          try {
            bw = new BufferedWriter(new FileWriter("textos.txt", true));
            bw.write(texto);
            bw.newLine();
            System.out.println("arquivo escrito com sucesso");
          } catch (Exception e) {
            System.out.println("Erro");
          }
          break;
        }
        case 2: {
          break;
        }
        case 3: {
          in = false;
          break;
        }
      }
    }

  }

  private void menuElemento() {
    System.out.println("--- selecione a opção ---");
    System.out.println(" 1. Inserior elemento    ");
    System.out.println(" 2. Imprimir a lista     ");
    System.out.println(" 3. Sair                 ");
  }

  private void resgatarTextoPorIndice(){
    System.out.println("Digite o indice do texto a ser resgatado: ");
    int indice = IO.readInt();
    String texto = lista.get(indice);
    System.out.println(texto);
  }

}
