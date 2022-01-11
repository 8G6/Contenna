void MaskState(HANDLE handle){

	if (SetCommMask(handle, EV_RXCHAR) == FALSE) //Configure Windows to Monitor the serial device for Character Reception
		printf("\n\n    Error! in Setting CommMask");
	else
		printf("\n\n    Setting CommMask successfull");
}

void EscapeState(HANDLE handle){
	if (EscapeCommFunction(handle, SETDTR) == TRUE)
		printf("\n\n    DE of MAX485 is Low (Receive Mode)");
	else
		printf("\n\n   Error! in EscapeCommFunction(handle, SETDTR)");
}

