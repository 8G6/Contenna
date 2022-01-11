
int SerialConfig(char port[]){

          
			HANDLE handle;  
			
			handle = CreateFile( port,                  
		                        GENERIC_READ | GENERIC_WRITE,
								0,                            // No Sharing, ports cant be shared
								NULL,                         // No Security
							    OPEN_EXISTING,              
		                        0,                          
		                        NULL                         //  Null for Comm Devices
							   );                        

			handle=DCBConfig(handle,9600,8,1,0);

			TimeoutConfig(handle);

			MaskState(handle);

			EscapeState(handle);
             
			handle=ReciveData(handle);

			CloseHandle(handle);//Closing the Serial Port
			

}