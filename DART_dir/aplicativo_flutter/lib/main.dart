import 'package:flutter/material.dart';

class MaterialExample extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.blue),
        useMaterial3: true,
      ),
      home: Scaffold(
        appBar: AppBar(
          title: Text('Material Design'),
          backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              ElevatedButton(
                onPressed: () {},
                child: Text('Botão Elevado'),
              ),
              SizedBox(height: 16),
              FloatingActionButton(
                onPressed: () {},
                child: Icon(Icons.add),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
