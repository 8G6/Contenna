
HANDLE DCBConfig(HANDLE handle){

    DCB DCBPara = { 0 };                 // Initializing DCB structure
	DCBPara.DCBlength = sizeof(DCBPara);
	DCBPara.BaudRate = CBR_9600;        // Setting BaudRate = 9600
	DCBPara.ByteSize = 8;        // Setting ByteSize = 8
	DCBPara.StopBits = ONESTOPBIT;        // Setting StopBits = 1
	DCBPara.Parity   = NOPARITY;          // Setting Parity = None 
	
	if(GetCommState(handle, &DCBPara) == FALSE)
		printf("\n    Error! in GetCommState()");
		
	if(SetCommState(handle, &DCBPara) == FALSE){   //Configuring the port according to settings in DCB 
		printf("\n    Error! in Setting DCB Structure");
	}
	else {
		printf("\n\n     Setting DCB Structure Successfull\n");
		printf("\n       Baudrate = %d", DCBPara.BaudRate);
		printf("\n       ByteSize = %d", DCBPara.ByteSize);
		printf("\n       StopBits = %d", DCBPara.StopBits);
		printf("\n       Parity   = %d", DCBPara.Parity);
	}
	return handle;
}

HANDLE TimeoutConfig(HANDLE handle){

	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout         = 50;
	timeouts.ReadTotalTimeoutConstant    = 50;
	timeouts.ReadTotalTimeoutMultiplier  = 10;
	timeouts.WriteTotalTimeoutConstant   = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;
    
	if (SetCommTimeouts(handle, &timeouts) == FALSE)
		printf("\n       rror! in Setting Time Outs\n");
	else
		printf("\n       Setting Serial Port Timeouts Successfull\n");

	return handle;
}