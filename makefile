
all: src/calculator.c src/calculatorAPI.c src/soap/soapC.c src/soap/soapClient.c src/soap/stdsoap2.c 
	gcc -o calculator ./src/calculator.c ./src/calculatorAPI.c ./src/soap/soapC.c ./src/soap/soapClient.c ./src/soap/stdsoap2.c -std=gnu99 -lrt

