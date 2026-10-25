import 'dart:convert';

import 'package:http/http.dart' as http;

int calculate() {
  return 6 * 7;
}

Future<void> getClientes() async {
  final url = Uri.parse('http://localhost:3000/clientes');
  final respose = await http.get(url);

  if(respose.statusCode == 200) {
    
    var response = jsonDecode(respose.body);
    var clientes = [];
    var telefones = [];
    for(var v in response){
      clientes.add(v['nome']);
      telefones.add(v['telefone']);
    }

    print(clientes);
    print(telefones);

  } else {
    print('Error: ${respose.statusCode}');
  }
}
