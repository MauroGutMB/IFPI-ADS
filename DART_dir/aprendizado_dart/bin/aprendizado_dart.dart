import 'dart:io';

void main() {
  print("Números: ");
  int a = int.parse(stdin.readLineSync()!);
  int b = int.parse(stdin.readLineSync()!);
  
  print(calculate(a, b));
} 

int calculate(int a, int b) {
  return a * b;
}

