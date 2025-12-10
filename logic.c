#include <stdio.h>
#include "renderer.c"
#include "move.c"
void fen(char data[8][8][4] ,int move , int fullmv,int fifty,FILE *filePtr){
    printf("\033[1;5;36;40m");
    printf("\033[80;181H FEN-");
    for(int i=0;i<8;i++){
        int count=0;
        for(int j=0;j<8;j++){
            if(data[i][j][0]==' '){
                count++;
            }
            else{
                if(count!=0){
                    printf("%d",count);
                    fprintf(filePtr,"%d",count);
                    printf("%c",data[i][j][0]);
                    fprintf(filePtr,"%c",data[i][j][0]);
                    count=0;
                }
                else{
                    printf("%c",data[i][j][0]);
                    fprintf(filePtr,"%c",data[i][j][0]);
                    
                }
            }
            
        }
        if(count!=0){
            printf("%d",count);
            fprintf(filePtr,"%d",count);
        }
        if(i!=7){
        printf("/");
        fprintf(filePtr,"/");
        }
    }
    if(move==1){
        printf("\b w ");
        fprintf(filePtr," w ");
    }
    else{
        printf("\b b ");
        fprintf(filePtr," b ");
    }
    if(data[7][7][1]=='C'&&data[7][4][1]=='C'){
        printf("K");
        fprintf(filePtr,"K");
    }
    else{
        printf("-");
        fprintf(filePtr,"-");
    }
    if(data[7][4][1]=='C'&&data[7][0][1]=='C'){
        printf("Q");
        fprintf(filePtr,"Q");
    }
    else{
        printf("-");
        fprintf(filePtr,"-");
    }
    if(data[0][7][1]=='C'&&data[0][4][1]=='C'){
        printf("k");
        fprintf(filePtr,"k");
    }
    else{
        printf("-");
        fprintf(filePtr,"-");
    }
    if(data[0][0][1]=='C'&&data[0][4][1]=='C'){
        printf("q");
        fprintf(filePtr,"q");
    }
    else{
        printf("-");
        fprintf(filePtr,"-");
    }
    printf(" - %d %d",fullmv,fifty/2);
    fprintf(filePtr," - %d %d\n",fullmv,fifty/2);
    
}


void pointer(int final[2],int prev[2],int set){
    int pos[2];
    if(set==0){
        pos[0]=0,pos[1]=0;
    }
    else{
        pos[0]=prev[0],pos[1]=prev[1];
    }
    int posbuff[2];
    char input;
    pointren(pos[0],pos[1]);
    while(1){
        posbuff[0]=pos[0];posbuff[1]=pos[1];
        input=getch();
        if(input=='w'||input=='a'||input=='s'||input=='d'||input=='y'){
            if(input=='w'){
                pos[0]--;
            }
            else if(input=='s'){
                pos[0]++;
            }
            else if(input=='a'){
                pos[1]--;
            }
            else if(input=='d'){
                pos[1]++;
            }
            else if(input=='y'){
                selectren(pos[0],pos[1]);
                final[0]=pos[0],final[1]=pos[1];
                break;
            }
        }
        else{
            continue;
        }
        if(pos[0]<0){
            pos[0]=7;
        }
        else if(pos[0]>7){
            pos[0]=0;
        }
        if(pos[1]<0){
            pos[1]=7;
        }
        else if(pos[1]>7){
            pos[1]=0;
        }
        if(posbuff[0]==prev[0]&&posbuff[1]==prev[1]){
            pointren(pos[0],pos[1]);
            selectren(posbuff[0],posbuff[1]);
        }
        else{
            pointren(pos[0],pos[1]);
            clrptrren(posbuff[0],posbuff[1]);
        }

    }
}

int check(char data[8][8][4]){
    //BLACK
    int i,j,found=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(data[i][j][0]=='k'){
                found=1;
                break;
            }
        }
        if(found==1){
            break;
        }
    }
    int bcheck=0;
    int pos[4]={0,0,i,j};
    for(int k=0;k<8;k++){
        for(int l=0;l<8;l++){
            pos[0]=k,pos[1]=l;
            if(move(data,1,pos,0,0)==1){
                bcheck++;
                bck();
            }
        }
    }
    //WHITE
    int wcheck=0;
    int a,b;
    found=0;
    for(a=0;a<8;a++){
        for(b=0;b<8;b++){
            if(data[a][b][0]=='K'){
                found=1;
                break;
            }
        }
        if(found==1){
            break;
        }
    }
    int posi[4]={0,0,a,b};
    for(int k=0;k<8;k++){
        for(int l=0;l<8;l++){
            posi[0]=k,posi[1]=l;
            if(move(data,2,posi,0,0)==1){
                wcheck++;
                wck();
            }
        }
    }
    if(bcheck==0&&wcheck==0){
        cck();
        return 0;
    }
    else{
        if(wcheck!=0&&bcheck==0){
            return 1;
        }
        else if(wcheck==0&&bcheck!=0){
            return 2;
        }
        else if(wcheck!=0&&bcheck!=0){
            return 3;
        }
    }

}


int checkmate(char data[8][8][4]){
    //RETURN 0 FOR NO CHECKMATE AND 1 FOR CHECKMATE
    int a=check(data);
    if(a==1){
        //WHITE
        int pos[4];
        char sbuffer[8][8][4]; 
        for(int A=0;A<8;A++){
            for(int B=0;B<8;B++){
                for(int C=0;C<8;C++){
                    for(int D=0;D<8;D++){  
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                sbuffer[i][j][0]=data[i][j][0];
                            }
                        }
                        pos[0]=A,pos[1]=B,pos[2]=C,pos[3]=D;
                        move(sbuffer,1,pos,1,0);
                        if(check(sbuffer)==2||check(sbuffer)==0){
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
    else if(a==2){
        //BLACK
        int pos[4];
        char sbuffer[8][8][4]; 
        for(int A=0;A<8;A++){
            for(int B=0;B<8;B++){
                for(int C=0;C<8;C++){
                    for(int D=0;D<8;D++){  
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                sbuffer[i][j][0]=data[i][j][0];
                            }
                        }
                        pos[0]=A,pos[1]=B,pos[2]=C,pos[3]=D;
                        move(sbuffer,2,pos,1,0);
                        if(check(sbuffer)==1||check(sbuffer)==0){
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}

int start(){
    //RESET
    FILE *filePtr;
    filePtr = fopen("FEN.txt", "w");
    char data[8][8][4];
    for(int k=0;k<4;k++){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                data[i][j][k]=' ';
            }
        }
    }
    for(int i=0;i<8;i++){
        data[1][i][0]='p';
        data[6][i][0]='P';
    }
    data[0][0][0]='r',data[0][1][0]='n',data[0][2][0]='b',data[0][3][0]='q',data[0][4][0]='k',data[0][5][0]='b',data[0][6][0]='n',data[0][7][0]='r';
    data[7][0][0]='R',data[7][1][0]='N',data[7][2][0]='B',data[7][3][0]='Q',data[7][4][0]='K',data[7][5][0]='B',data[7][6][0]='N',data[7][7][0]='R';
    data[0][0][1]='C',data[7][4][1]='C',data[0][4][1]='C',data[7][0][1]='C',data[0][7][1]='C',data[7][7][1]='C';
    display(data);

    //main loop
    int mv=1; //1 for white , 2 for black
    wmv();
    int zm=0,ym=0,chkmt=0;
    int bf=1,gf=0,ini;
    while(mv==1||mv==2){
        
        ini=check(data);
        int initial[2]={8,8},final[2]={0,0};
        pointer(final,initial,0);
        initial[0]=final[0],initial[1]=final[1];
        pointer(final,initial,1);
        int pos[4]={initial[0],initial[1],final[0],final[1]};
        if(ini!=0){
            char buffer[8][8][4];
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    buffer[i][j][0]=data[i][j][0];
                    buffer[i][j][1]=' ';
                    buffer[i][j][2]=' ';
                    buffer[i][j][3]=' ';
                }
            }
            bf=move(buffer,mv,pos,1,0);
            if(bf!=1){
                clrptrren(initial[0],initial[1]);
                clrptrren(final[0],final[1]);
                continue;
            }
            gf=check(buffer);
            if(gf!=0){
                clrptrren(initial[0],initial[1]);
                clrptrren(final[0],final[1]);
                continue;
            }
        }
        char sbuffer[8][8][4];            
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                sbuffer[i][j][0]=data[i][j][0];
            }
        }
        int cf=move(sbuffer,mv,pos,1,0);
        if(cf==1){
            if(((mv==1&&check(sbuffer)==1))||(mv==2&&check(sbuffer)==2)){
                clrptrren(initial[0],initial[1]);
                clrptrren(final[0],final[1]);
                cf=10;
            }
        }
        if(bf!=1||gf==1||cf==10){
            continue;
        }
        int ck=move(data,mv,pos,1,1);
        if(ck==1){
            if(mv==2){
                mv=1;
                wmv();
            }
            else if(mv==1){
                mv=2;
                bmv();
            }
        }
        if((data[initial[0]][initial[1]][0]!='p'||data[final[0]][final[1]][0]==' ')){
            ym++;
        }
        else{
            ym=0;
        }
        
        if(checkmate(data)==1){
            printf("\033[10;179H");
            printf("\033[1;5;36;40m CHECKMATE . \033[B ENTER ANYTHING TO CLOSE.\a");
            break;
        }
        else if(ym==100){
            break;
            printf("\033[10;179H");
            printf("\033[1;5;36;40m DRAW BY 50 MOVE RULE . \033[B ENTER ANYTHING TO CLOSE.\a");
        }
        fen(data,mv,zm/2,ym,filePtr);
        clrptrren(initial[0],initial[1]);
        clrptrren(final[0],final[1]);
        zm++;
    }
    scanf("%d",&mv);
}



