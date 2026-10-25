// Cliente premium
// compra >= 500
// compra >= 300
// compra >= 200
// cupom valido
import 'test.dart';

class Resultados {
  List<bool> a = [];
  bool premium;
  bool m500;
  bool m300;
  bool m200;
  bool cupom;

  Resultados(this.premium, this.m500, this.m300, this.m200, this.cupom) {
    a.add(premium);
    a.add(m500);
    a.add(m300);
    a.add(m200);
    a.add(cupom);
  }
}

void main(List<String> args) {
  List<Resultados> lista = [];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          for (int m = 0; m < 2; m++) {
            // Usando == 1 para manter o padrão lógico em todas as variáveis (1 = True, 0 = False)
            Resultados r = Resultados(i == 1, j == 1, k == 1, l == 1, m == 1);
            lista.add(r);
          }
        }
      }
    }
  }

  for (Resultados r in lista) {
    print("-------");
    print(
      "premium: ${r.premium}, m500: ${r.m500}, m300: ${r.m300}, m200: ${r.m200}, cupom: ${r.cupom}",
    );
  }

  // for(Resultados r in lista){
  //   print("-------");
  //   testUseActions(r);
  // }
}
