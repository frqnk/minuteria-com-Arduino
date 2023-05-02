// estadoDeFuncionamento utiliza lógica invertida
bool *estadoDeFuncionamento = (bool*)malloc(sizeof(bool));
unsigned long momentoDoAcionamento;

void setup(){
	*estadoDeFuncionamento = !*estadoDeFuncionamento;
	if(*estadoDeFuncionamento == 0) momentoDoAcionamento = millis();
  	pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
	if(*estadoDeFuncionamento == 0){
		unsigned long periodoDesdeOAcionamento = millis()-momentoDoAcionamento;
		if(periodoDesdeOAcionamento >= 60000) *estadoDeFuncionamento = 1;
		else if(periodoDesdeOAcionamento >= 50000) digitalWrite(LED_BUILTIN, 1);
		else if(periodoDesdeOAcionamento >= 49000) digitalWrite(LED_BUILTIN, 0);
		else if(periodoDesdeOAcionamento >= 48000) digitalWrite(LED_BUILTIN, 1);
		else if(periodoDesdeOAcionamento >= 47000) digitalWrite(LED_BUILTIN, 0);
		else if(periodoDesdeOAcionamento >= 37000) digitalWrite(LED_BUILTIN, 1);
		else if(periodoDesdeOAcionamento >= 36000) digitalWrite(LED_BUILTIN, 0);
		else digitalWrite(LED_BUILTIN, 1);
	}
	else digitalWrite(LED_BUILTIN, 0);
	delay(250);
}

/*
Referências:
https://arduino.stackexchange.com/questions/32378/how-do-i-repurpose-arduinos-reset-button
*/