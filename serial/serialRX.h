
HANDLE ReciveData(HANDLE handle){
	char  TempChar;                          // Temperory Character
	DWORD NoBytesRecieved;                  // Bytes read by ReadFile()
	DWORD dwEventMask;                     // Event mask to trigger

	if (WaitCommEvent(handle, &dwEventMask, NULL) == FALSE){ //Wait for the character to be received
			printf("\n    Error! in Setting WaitCommEvent()");
	}
	else{
		while(1){ 
			ReadFile(handle, &TempChar, sizeof(TempChar), &NoBytesRecieved, NULL);
			if(!NoBytesRecieved)
			printf("\n__%c__\n",TempChar);
		}
		
	}

}