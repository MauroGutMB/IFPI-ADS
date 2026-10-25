import 'atividade.dart';

bool _desconto10porcento(Resultados r){
  if(r.premium && r.m300)return true;
  return false;
}

bool _freteGratis(Resultados r){
  if(r.m500)return true;
  return false;
}

bool _cupomAdicional5porcento(Resultados r){
  if(r.cupom && r.m200)return true;
  return false;
}

void testUseActions(Resultados r){
  // 10% desconto
  if(_desconto10porcento(r)){
    print("O usuário possui 10% de desconto.");
  } else {
    print("O usuário não possui desconto.");
  }
  // frete gratis
  if(_freteGratis(r)){
    print("O usuário possui frete grátis.");
  } else {
    print("O usuário não possui frete grátis.");
  }
  // Cupom adicional
  if(_cupomAdicional5porcento(r)){
    print("O usuário possui 5% de cupom.");
  } else {
    print("O usuário não possui cupom.");
  }
}
