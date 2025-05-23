#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H
class Temporizador {
  private:
    unsigned long intervalo;  
    unsigned long  iniciaTemporizador;    
    bool ativo;              

  public:
   
    Temporizador(unsigned long ) {
     
      inicio = 0;
      ativo = false;
    }

    void iniciar() {
   
    }
    void parar() {
      ativo = false;     
    }
    bool estaPronto() {
    
    }

    void reiniciar() {
      inicio = millis();
    }
    bool estaAtivo() {
      return ativo; 
    }
    void definirIntervalo
{





}

#endif};