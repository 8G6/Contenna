
void connect(char *port){
	

			handle = CreateFile(port,                  
		                        GENERIC_READ | GENERIC_WRITE,
								0,                            // No Sharing, ports cant be shared
								NULL,                         // No Security
							    OPEN_EXISTING,              
		                        0,                          
		                        NULL                         //  Null for Comm Devices
							   );   
							
			if (handle == INVALID_HANDLE_VALUE)
				printf("\n    Error! - Port %s can't be opened\n", port);
			else
				printf("\n    Port %s Opened\n ", port);
			
			     
}  
