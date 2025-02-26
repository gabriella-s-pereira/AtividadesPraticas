// C++ code
// 
void setup()
{
 Serial.begin(9600);
    
float peso=42;
float altura=1.45;
float imc = peso / (altura* altura);


  if(imc<18.5){
Serial.print("Abaixo do peso");
   
  }else if(imc >= 18.5 && imc < 24.9){
Serial.println("peso nornal");
  
}else if(imc >= 25 && imc < 29.9){
Serial.println("excesso de peso");
    
  }else if(imc >= 30 && imc < 34.9){
Serial.println("obesidade");
  
}else if(imc >= 35 && imc<39.9){
Serial.println("obesidade avancada");
    
}else{
  Serial.println("obesidade");
}
  
}
void loop()
{

}