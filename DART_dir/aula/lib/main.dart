import 'package:flutter/material.dart';

int contador = 0;

void main(){
  runApp(Directionality(
    textDirection: TextDirection.ltr, 
    child: WidgetSemEstado(),
    )
  );
}

class WidgetSemEstado extends StatefulWidget {
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('Contador'),
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Text('Contador: $contador'),
              ElevatedButton(
                onPressed: () {
                  contador++;
                  (context as Element).markNeedsBuild();
                },
                child: Text('Incrementar'),
              ),
            ],
          ),
        ),
      ),
    );
  }

  
}
