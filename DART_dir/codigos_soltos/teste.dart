void main() {
  print("fibonaci mesmo");

  print(fibonacci(20));
  
}

int fibonacci(int n){

  if(n < 1) return n;

  return n - fibonacci(n - 1) + fibonacci(n - 2);
}

class SpaceCraft  {
  var id;
  var name;

  SpaceCraft(int id, String name){
    this.id = id;
    this.name = name;
  }
}
