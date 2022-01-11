

char *cmd = "powershell \"$portList = get-pnpdevice -class Ports -ea 0;if ($portList) {foreach($device in $portList) {if ($device.Present) {Write-Host $device.FriendlyName''$device.Status}}}\"";

int pipe(char* cmd,char* copy){
         
    int i=0;
    FILE *Terminal;
    char path[PATH_MAX];
    
    Terminal = popen(cmd, "r");

    
    if (Terminal == NULL){
        printf("Pipeline Error");
    }
    
    while(fgets(path,PATH_MAX,Terminal)!=NULL){
        printf("");
    }
    for(i=0;i<PATH_MAX;i++){
        copy[i]=path[i];
    }
    
    int out=pclose(Terminal);

    out==0 && printf("cammand runned sucessfully\n");
    out!=0 && printf("cammand failed\n");
}

void FindPort(char PORT[]){

    char str[PATH_MAX];
    pipe(cmd,str);
    int i=0,s=0,e=0,j=0;
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='(')
            s=i+1;
        else if(str[i]==')'){
            e=i;
            break;
        }
    }
    for(i=s;i<e;i++){
        PORT[j]=str[i];
        j++;
    }
    
}

