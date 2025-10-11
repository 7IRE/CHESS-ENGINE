#include <stdio.h>
#define debug 0
//return 1 for successfull move and 0 for unsuccessful move
 //1 for white , 2 for black in move
int bpath(char data[8][8][4],int pos[4]){
/*
4               3
    .       .
        .
    .   -   .
1               2
  4 directions*/
    //PATH = 0-No,1-Yes
    if(abs(pos[0]-pos[2])!=abs(pos[1]-pos[3])){
        return 0;
    }
    //-------------
    if((pos[0]<pos[2])&&(pos[1]>pos[3])){
        for(int loop=1;loop<abs(pos[0]-pos[2]);loop++){
            if(data[pos[0]+loop][pos[1]-loop][0]!=' '){
                return 0;
            }
        }
        return 1;
    }
    else if((pos[0]<pos[2])&&(pos[1]<pos[3])){
        for(int loop=1;loop<abs(pos[0]-pos[2]);loop++){
            if(data[pos[0]+loop][pos[1]+loop][0]!=' '){
                return 0;
            }
        }
        return 1;
    }
    else if((pos[0]>pos[2])&&(pos[1]<pos[3])){
        for(int loop=1;loop<abs(pos[0]-pos[2]);loop++){
            if(data[pos[0]-loop][pos[1]+loop][0]!=' '){
                return 0;
            }
        }
        return 1;
    }
    else if((pos[0]>pos[2])&&(pos[1]>pos[3])){
        for(int loop=1;loop<abs(pos[0]-pos[2]);loop++){
            if(data[pos[0]-loop][pos[1]-loop][0]!=' '){
                return 0;
            }
        }
        return 1;
    }
}

int rpath(char data[8][8][4],int pos[4]){
    int a=0;
    // vertical movement
    if((pos[0]<pos[2])&&(pos[1]==pos[3])){
        for(int loop=1;pos[2]>(pos[0]+loop);loop++){
            if(data[pos[0]+loop][pos[1]][0]!=' '){
                a=1;
                break;
            }
        }
        if(a==1){
            return 0;
        }
        else{
            return 1;
        }
    }
    if((pos[0]>pos[2])&&(pos[1]==pos[3])){
       for(int loop=1;pos[0]>(pos[2]+loop);loop++){
            if(data[pos[2]+loop][pos[1]][0]!=' '){
                a=1;
                break;
            }
        }
        if(a==1){
            return 0;
        }
        else{
            return 1;
        } 
    
        
    }
    //horizontal movement
    if((pos[1]<pos[3])&&(pos[0]==pos[2])){
        for(int loop=1;pos[3]>(pos[1]+loop);loop++){
            if(data[pos[0]][pos[1]+loop][0]!=' '){
                a=1;
                break;
            }
        }
        if(a==1){
            return 0;
        }
        else{
            return 1;
        } 
    }
    if((pos[1]>pos[3])&&(pos[0]==pos[2])){
        for(int loop=1;pos[1]>(pos[3]+loop);loop++){
            if(data[pos[0]][pos[3]+loop][0]!=' '){
                a=1;
                break;
            }
        }
        if(a==1){
            return 0;
        }
        else{
            return 1;
        } 
    }
    return 0;
}

int qpath(char data[8][8][4],int pos[4]){
    int b;
    if(abs(pos[0]-pos[2])!=abs(pos[1]-pos[3])){
        b = rpath(data,pos);
    }
    else{
        b = bpath(data,pos);
    }
    return b;
} 


int move(char data[8][8][4],int move,int pos[4],int update,int render){
    if(debug==1){
        debugpt(pos[0],pos[1],pos[2],pos[3],move,data[pos[0]][pos[1]][0],data[pos[2]][pos[3]][0],'a','b');
    }
    if(data[pos[0]][pos[1]][0]==' '||((pos[0]==pos[2])&&pos[1]==pos[3])){
        return 0;
    }
    if((move==1)&&(data[pos[0]][pos[1]][0]=='q'||data[pos[0]][pos[1]][0]=='k'||data[pos[0]][pos[1]][0]=='b'||data[pos[0]][pos[1]][0]=='n'||data[pos[0]][pos[1]][0]=='r'||data[pos[0]][pos[1]][0]=='p')){
        return 0;
    }
    if((move==2)&&(data[pos[0]][pos[1]][0]=='Q'||data[pos[0]][pos[1]][0]=='K'||data[pos[0]][pos[1]][0]=='B'||data[pos[0]][pos[1]][0]=='N'||data[pos[0]][pos[1]][0]=='R'||data[pos[0]][pos[1]][0]=='P')){
        return 0;
    }

    //WHITE
    if(move==1){
        for(int i=0;i<8;i++){
            data[4][i][1]=' ';
        }
        if(data[pos[0]][pos[1]][0]=='R'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'||data[pos[2]][pos[3]][0]=='n'||data[pos[2]][pos[3]][0]=='p'||data[pos[2]][pos[3]][0]=='k'||data[pos[2]][pos[3]][0]=='q')){
            if(rpath(data,pos)==1){
                if(update==1){
                data[pos[0]][pos[1]][0]=' ';
                data[pos[2]][pos[3]][0]='R';
                if(pos[0]==7&&pos[1]==0){
                    data[7][0][1]=' ';
                }
                else if(pos[0]==7&&pos[1]==7){
                    data[7][7][1]=' ';
                }
                if(render==1){
                wcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                wcolor(pos[2],pos[3]);
                rookren(pos[2],pos[3]);
                }}
                return 1;
            }
            return 0;
        }
        if(data[pos[0]][pos[1]][0]=='B'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'||data[pos[2]][pos[3]][0]=='n'||data[pos[2]][pos[3]][0]=='p'||data[pos[2]][pos[3]][0]=='k'||data[pos[2]][pos[3]][0]=='q')){
            if(bpath(data,pos)==1){
                if(update==1){
                data[pos[0]][pos[1]][0]=' ';
                data[pos[2]][pos[3]][0]='B';
                if(render==1){
                wcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                wcolor(pos[2],pos[3]);
                bishopren(pos[2],pos[3]);
                }}
                return 1;
            }
            return 0;
        }
        if(data[pos[0]][pos[1]][0]=='Q'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'||data[pos[2]][pos[3]][0]=='n'||data[pos[2]][pos[3]][0]=='p'||data[pos[2]][pos[3]][0]=='k'||data[pos[2]][pos[3]][0]=='q')){
            if(qpath(data,pos)==1){
                if(update==1){
                data[pos[0]][pos[1]][0]=' ';
                data[pos[2]][pos[3]][0]='Q';
                if(render==1){
                wcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                wcolor(pos[2],pos[3]);
                queenren(pos[2],pos[3]);
                }}
                return 1;
                
            }
            return 0;
        }
        if(data[pos[0]][pos[1]][0]=='P'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'||data[pos[2]][pos[3]][0]=='n'||data[pos[2]][pos[3]][0]=='p'||data[pos[2]][pos[3]][0]=='k'||data[pos[2]][pos[3]][0]=='q')){
            if(pos[1]==pos[3]){
                if(pos[0]==pos[2]+1){
                    if(data[pos[2]][pos[3]][0]==' '){
                        if(update==1){
                        if(pos[2]==0){
                            data[pos[2]][pos[3]][0]=getch();
                            if(data[pos[2]][pos[3]][0]=='N'||data[pos[2]][pos[3]][0]=='Q'||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'){

                            }
                            else{
                                data[pos[2]][pos[3]][0]=' ';
                                return 0;
                            }
                            if(render==1){
                            wcolor(pos[2],pos[3]);
                            if(data[pos[2]][pos[3]][0]=='Q'){
                                queenren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='R'){
                                rookren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='B'){
                                bishopren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='N'){
                                knightren(pos[2],pos[3]);
                            }}
                        }
                        else{
                        data[pos[2]][pos[3]][0]='P';
                        if(render==1){
                        wcolor(pos[2],pos[3]);
                        pawnren(pos[2],pos[3]); 
                        }}
                        data[pos[0]][pos[1]][0]=' ';
                        if(render==1){
                        wcolor(pos[0],pos[1]);
                        emptyren(pos[0],pos[1]);
                        wcolor(pos[2],pos[3]);
                        }}
                        return 1;
                    }
                }
                else if(pos[0]==pos[2]+2){
                    if((data[pos[0]-1][pos[1]][0]==' ') && (data[pos[2]][pos[3]][0]==' ')){
                        if(update==1){
                        data[pos[2]][pos[3]][0]='P';
                        data[pos[2]][pos[3]][1]='E';
                        data[pos[0]][pos[1]][0]=' ';
                        if(render==1){
                        wcolor(pos[0],pos[1]);
                        emptyren(pos[0],pos[1]);
                        wcolor(pos[2],pos[3]);
                        pawnren(pos[2],pos[3]);
                        }}
                        return 1;
                    }
                }        
            }
            else if((pos[1]==pos[3]+1)&&(pos[0]==pos[2]+1)&&(data[pos[2]][pos[3]][0]=='p'||data[pos[2]][pos[3]][0]=='q'||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'||data[pos[2]][pos[3]][0]=='k'||data[pos[2]][pos[3]][0]=='n')){
                if(update==1){
                if(pos[2]==0){
                    data[pos[2]][pos[3]][0]=getch();
                    int buffer = data[pos[2]][pos[3]][0];
                    if(data[pos[2]][pos[3]][0]=='N'||data[pos[2]][pos[3]][0]=='Q'||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'){
                        }
                        else{
                            data[pos[2]][pos[3]][0]=buffer;
                            return 0;
                        }
                        if(render==1){
                        wcolor(pos[2],pos[3]);
                        if(data[pos[2]][pos[3]][0]=='Q'){
                            queenren(pos[2],pos[3]);
                        }
                        else if(data[pos[2]][pos[3]][0]=='R'){
                            rookren(pos[2],pos[3]);
                        }
                        else if(data[pos[2]][pos[3]][0]=='B'){
                            bishopren(pos[2],pos[3]);
                        }
                        else if(data[pos[2]][pos[3]][0]=='N'){
                            knightren(pos[2],pos[3]);
                        }}
                    }
                    else{
                        data[pos[2]][pos[3]][0]='P';
                        if(render==1){
                        wcolor(pos[2],pos[3]);
                        pawnren(pos[2],pos[3]); 
                    }}
                data[pos[0]][pos[1]][0]=' ';
                if(render==1){
                wcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]); 
                }}
                return 1;
            }
            else if((pos[1]==pos[3]-1)&&(pos[0]==pos[2]+1)&&(data[pos[2]][pos[3]][0]=='p'||data[pos[2]][pos[3]][0]=='q'||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'||data[pos[2]][pos[3]][0]=='k'||data[pos[2]][pos[3]][0]=='n')){
                if(update==1){
                    if(pos[2]==0){
                        int buffer = data[pos[2]][pos[3]][0];
                        data[pos[2]][pos[3]][0]=getch();
                        if(data[pos[2]][pos[3]][0]=='N'||data[pos[2]][pos[3]][0]=='Q'||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'){

                            }
                            else{
                                data[pos[2]][pos[3]][0]=buffer;
                                return 0;
                            }
                            if(render==1){
                            wcolor(pos[2],pos[3]);
                            if(data[pos[2]][pos[3]][0]=='Q'){
                                queenren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='R'){
                                rookren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='B'){
                                bishopren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='N'){
                                knightren(pos[2],pos[3]);
                            }}
                    }
                    else{
                        data[pos[2]][pos[3]][0]='P';
                        if(render==1){
                        wcolor(pos[2],pos[3]);
                        pawnren(pos[2],pos[3]); 
                        }}
                data[pos[0]][pos[1]][0]=' ';
                if(render==1){
                wcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                }}
                return 1;
            }
            else if((pos[1]==pos[3]-1)&&(pos[0]==pos[2]+1)&&(data[pos[0]][pos[3]][1]=='E')){
                if(update==1){
                data[pos[2]][pos[3]][0]='P';
                data[pos[0]][pos[1]][0]=' ';
                data[pos[0]][pos[3]][0]=' ';
                if(render==1){
                wcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                wcolor(pos[0],pos[3]);
                emptyren(pos[0],pos[3]);
                wcolor(pos[2],pos[3]);
                pawnren(pos[2],pos[3]);
                }}
                return 1;
            }
            else if((pos[1]==pos[3]+1)&&(pos[0]==pos[2]+1)&&(data[pos[0]][pos[3]][1]=='E')){
                if(update==1){
                data[pos[2]][pos[3]][0]='P';
                data[pos[0]][pos[1]][0]=' ';
                data[pos[0]][pos[3]][0]=' ';
                if(render==1){
                wcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                wcolor(pos[0],pos[3]);
                emptyren(pos[0],pos[3]);
                wcolor(pos[2],pos[3]);
                pawnren(pos[2],pos[3]);
                }}
                return 1;
            } 
        return 0;
        }
        if(data[pos[0]][pos[1]][0]=='N'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'||data[pos[2]][pos[3]][0]=='n'||data[pos[2]][pos[3]][0]=='p'||data[pos[2]][pos[3]][0]=='k'||data[pos[2]][pos[3]][0]=='q')){
            if(((abs(pos[3]-pos[1])==2)&&(abs(pos[2]-pos[0])==1))||(abs(pos[3]-pos[1])==1)&&(abs(pos[2]-pos[0])==2)){
                if(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='p'||data[pos[2]][pos[3]][0]=='q'||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'||data[pos[2]][pos[3]][0]=='k'||data[pos[2]][pos[3]][0]=='n'){
                    if(update==1){
                    data[pos[2]][pos[3]][0]='N';
                    data[pos[0]][pos[1]][0]=' ';
                    if(render==1){
                    wcolor(pos[0],pos[1]);
                    emptyren(pos[0],pos[1]);
                    wcolor(pos[2],pos[3]);
                    knightren(pos[2],pos[3]);
                    }}
                    return 1;
                }
            }
        return 0;
        }
        if(data[pos[0]][pos[1]][0]=='K'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'||data[pos[2]][pos[3]][0]=='n'||data[pos[2]][pos[3]][0]=='p'||data[pos[2]][pos[3]][0]=='k'||data[pos[2]][pos[3]][0]=='q')){
            if(((data[pos[0]][pos[1]][0]==data[pos[2]-1][pos[3]][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]-1][pos[3]-1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]-1][pos[3]+1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]][pos[3]-1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]][pos[3]+1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]+1][pos[3]][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]+1][pos[3]-1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]+1][pos[3]+1][0])) && ((data[pos[2]][pos[3]][0]==' ')||(data[pos[2]][pos[3]][0]=='k')||(data[pos[2]][pos[3]][0]=='q')||(data[pos[2]][pos[3]][0]=='p')||(data[pos[2]][pos[3]][0]=='r')||(data[pos[2]][pos[3]][0]=='b')||(data[pos[2]][pos[3]][0]=='n'))){
                if(update==1){
                data[pos[2]][pos[3]][0]='K';
                data[pos[0]][pos[1]][0]=' ';
                if(pos[0]==7&&pos[1]==3){
                    data[7][4][1]=' ';
                }
                if(render==1){
                wcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                wcolor(pos[2],pos[3]);
                kingren(pos[2],pos[3]);
                }}
                return 1;
            }
            else
            return 0;
        }
        else if(data[pos[0]][pos[1]][0]=='K'&&data[pos[2]][pos[3]][0]=='R'&&data[pos[0]][pos[1]][1]=='C'&&data[pos[2]][pos[3]][1]=='C'){
            int p[4]={pos[2],pos[3],pos[0],pos[1]};
            int r=rpath(data,p);
            if (r==1){
                if(pos[1]<pos[3]){
                    if(update==1){
                    data[pos[0]][pos[1]][0]=' ';
                    data[pos[2]][pos[3]][0]=' ';
                    data[pos[0]][pos[1]][1]=' ';
                    data[pos[2]][pos[3]][1]=' ';
                    data[pos[0]][pos[1]+2][0]='K';
                    data[pos[0]][pos[1]+1][0]='R';
                    if(render==1){
                    wcolor(pos[0],pos[1]);
                    emptyren(pos[0],pos[1]);
                    wcolor(pos[2],pos[3]);
                    emptyren(pos[2],pos[3]);
                    wcolor(pos[0],pos[1]+2);
                    kingren(pos[0],pos[1]+2);
                    wcolor(pos[0],pos[1]+1);
                    rookren(pos[0],pos[1]+1);
                    }}
                    return 1;
                }
                else if(pos[1]>pos[3]){
                    if(update==1){
                    data[pos[0]][pos[1]][0]=' ';
                    data[pos[2]][pos[3]][0]=' ';
                    data[pos[0]][pos[1]][1]=' ';
                    data[pos[2]][pos[3]][1]=' ';
                    data[pos[0]][pos[1]-2][0]='K';
                    data[pos[0]][pos[1]-1][0]='R';
                    if(render==1){
                    wcolor(pos[0],pos[1]);
                    emptyren(pos[0],pos[1]);
                    wcolor(pos[2],pos[3]);
                    emptyren(pos[2],pos[3]);
                    wcolor(pos[0],pos[1]-2);
                    kingren(pos[0],pos[1]-2);
                    wcolor(pos[0],pos[1]-1);
                    rookren(pos[0],pos[1]-1);
                    }}
                    return 1;
                }
            }
            else{
                return 0;
            }
        }
        return 0;
    }
    //BLACK
    if(move==2){
        for(int i=0;i<8;i++){
            data[3][i][1]=' ';
        }
        if(data[pos[0]][pos[1]][0]=='r'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'||data[pos[2]][pos[3]][0]=='N'||data[pos[2]][pos[3]][0]=='P'||data[pos[2]][pos[3]][0]=='K'||data[pos[2]][pos[3]][0]=='Q')){
            if(rpath(data,pos)==1){   
                if(update==1){
                data[pos[0]][pos[1]][0]=' ';
                data[pos[2]][pos[3]][0]='r';
                if(pos[0]==0&&pos[1]==0){
                    data[0][0][1]=' ';
                }
                else if(pos[0]==0&&pos[1]==7){
                    data[0][7][1]=' ';
                }
                if(render==1){
                bcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                bcolor(pos[2],pos[3]);
                rookren(pos[2],pos[3]);
                }}
                return 1;
            }
        }
        else if(data[pos[0]][pos[1]][0]=='b'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'||data[pos[2]][pos[3]][0]=='N'||data[pos[2]][pos[3]][0]=='P'||data[pos[2]][pos[3]][0]=='K'||data[pos[2]][pos[3]][0]=='Q')){
            if(bpath(data,pos)==1){ 
                if(update==1){  
                data[pos[0]][pos[1]][0]=' ';
                data[pos[2]][pos[3]][0]='b';
                if(render==1){
                bcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                bcolor(pos[2],pos[3]);
                bishopren(pos[2],pos[3]);
                }}
                return 1;
            }
            return 0;
        }
        else if(data[pos[0]][pos[1]][0]=='q'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'||data[pos[2]][pos[3]][0]=='N'||data[pos[2]][pos[3]][0]=='P'||data[pos[2]][pos[3]][0]=='K'||data[pos[2]][pos[3]][0]=='Q')){
            if(qpath(data,pos)==1){   
                if(update==1){
                data[pos[0]][pos[1]][0]=' ';
                data[pos[2]][pos[3]][0]='q';
                if(render==1){
                bcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                bcolor(pos[2],pos[3]);
                queenren(pos[2],pos[3]);
                }}
                return 1;
            }
            return 0;
        }
        else if(data[pos[0]][pos[1]][0]=='p'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'||data[pos[2]][pos[3]][0]=='N'||data[pos[2]][pos[3]][0]=='P'||data[pos[2]][pos[3]][0]=='K'||data[pos[2]][pos[3]][0]=='Q')){
            if(pos[1]==pos[3]){
                if(pos[0]==pos[2]-1){
                    if(data[pos[2]][pos[3]][0]==' '){
                        if(update==1){
                        if(pos[2]==7){
                            data[pos[2]][pos[3]][0]=getch();
                            if(data[pos[2]][pos[3]][0]=='n'||data[pos[2]][pos[3]][0]=='q'||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'){

                            }
                            else{
                                data[pos[2]][pos[3]][0]=' ';
                                return 0;
                            }
                            if(render==1){
                            bcolor(pos[2],pos[3]);
                            if(data[pos[2]][pos[3]][0]=='q'){
                                queenren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='r'){
                                rookren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='b'){
                                bishopren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='n'){
                                knightren(pos[2],pos[3]);
                            }}
                        }
                        else{
                        data[pos[2]][pos[3]][0]='p';
                        if(render==1){
                        bcolor(pos[2],pos[3]);
                        pawnren(pos[2],pos[3]); 
                        }}
                        data[pos[0]][pos[1]][0]=' ';
                        if(render==1){
                        bcolor(pos[0],pos[1]);
                        emptyren(pos[0],pos[1]);
                        }}
                        return 1;
                        
                    }
                }
                else if(pos[0]==pos[2]-2){
                    if((data[pos[0]+1][pos[1]][0]==' ') && (data[pos[2]][pos[3]][0]==' ')){
                        if(update==1){
                        data[pos[2]][pos[3]][0]='p';
                        data[pos[2]][pos[3]][1]='E';
                        data[pos[0]][pos[1]][0]=' ';
                        if(render==1){
                        bcolor(pos[0],pos[1]);
                        emptyren(pos[0],pos[1]);
                        bcolor(pos[2],pos[3]);
                        pawnren(pos[2],pos[3]);
                        }}
                        return 1;
                        
                    }
                }
            }
            else if((pos[1]==pos[3]+1)&&(pos[0]==pos[2]-1)&&(data[pos[2]][pos[3]][0]=='P'||data[pos[2]][pos[3]][0]=='Q'||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'||data[pos[2]][pos[3]][0]=='K'||data[pos[2]][pos[3]][0]=='N')){
                    if(update==1){
                        if(pos[2]==7){
                            int buffer = data[pos[2]][pos[3]][0];
                            data[pos[2]][pos[3]][0]=getch();
                            if(data[pos[2]][pos[3]][0]=='n'||data[pos[2]][pos[3]][0]=='q'||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'){

                            }
                            else{
                                data[pos[2]][pos[3]][0]=buffer;
                                return 0;
                            }
                            if(render==1){
                            bcolor(pos[2],pos[3]);
                            if(data[pos[2]][pos[3]][0]=='q'){
                                queenren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='r'){
                                rookren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='b'){
                                bishopren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='n'){
                                knightren(pos[2],pos[3]);
                            }}
                        }
                        else{
                        data[pos[2]][pos[3]][0]='p';
                        if(render==1){
                        bcolor(pos[2],pos[3]);
                        pawnren(pos[2],pos[3]); 
                        }}
                    data[pos[0]][pos[1]][0]=' ';
                    if(render==1){
                    bcolor(pos[0],pos[1]);
                    emptyren(pos[0],pos[1]);
                    }}
                    return 1;
            }
            else if((pos[1]==pos[3]-1)&&(pos[0]==pos[2]-1)&&(data[pos[2]][pos[3]][0]=='P'||data[pos[2]][pos[3]][0]=='Q'||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'||data[pos[2]][pos[3]][0]=='K'||data[pos[2]][pos[3]][0]=='N')){
                if(update==1){
                    if(pos[2]==7){
                            int buffer = data[pos[2]][pos[3]][0];
                            data[pos[2]][pos[3]][0]=getch();
                            if(data[pos[2]][pos[3]][0]=='n'||data[pos[2]][pos[3]][0]=='q'||data[pos[2]][pos[3]][0]=='r'||data[pos[2]][pos[3]][0]=='b'){

                            }
                            else{
                                data[pos[2]][pos[3]][0]=buffer;
                                return 0;
                            }
                            if(render==1){
                            bcolor(pos[2],pos[3]);
                            if(data[pos[2]][pos[3]][0]=='q'){
                                queenren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='r'){
                                rookren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='b'){
                                bishopren(pos[2],pos[3]);
                            }
                            else if(data[pos[2]][pos[3]][0]=='n'){
                                knightren(pos[2],pos[3]);
                            }}
                        }
                        else{
                        data[pos[2]][pos[3]][0]='p';
                        if(render==1){
                        bcolor(pos[2],pos[3]);
                        pawnren(pos[2],pos[3]); 
                        }}
                data[pos[0]][pos[1]][0]=' ';
                if(render==1){
                bcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                }}
                return 1;
            }
            else if((pos[1]==pos[3]-1)&&(pos[0]==pos[2]-1)&&(data[pos[0]][pos[3]][1]=='E')){
                if(update==1){
                data[pos[2]][pos[3]][0]='p';
                data[pos[0]][pos[1]][0]=' ';
                data[pos[0]][pos[3]][0]=' ';
                if(render==1){
                bcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                bcolor(pos[0],pos[3]);
                emptyren(pos[0],pos[3]);
                bcolor(pos[2],pos[3]);
                pawnren(pos[2],pos[3]);
                }}
                return 1;
            }
            else if((pos[1]==pos[3]+1)&&(pos[0]==pos[2]-1)&&(data[pos[0]][pos[3]][1]=='E')){
                if(update==1){
                data[pos[2]][pos[3]][0]='p';
                data[pos[0]][pos[1]][0]=' ';
                data[pos[0]][pos[3]][0]=' ';
                if(render==1){
                bcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                bcolor(pos[0],pos[3]);
                emptyren(pos[0],pos[3]);
                bcolor(pos[2],pos[3]);
                pawnren(pos[2],pos[3]);
                }}
                return 1;
            } 
            return 0; 
        }
        else if(data[pos[0]][pos[1]][0]=='n'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'||data[pos[2]][pos[3]][0]=='N'||data[pos[2]][pos[3]][0]=='P'||data[pos[2]][pos[3]][0]=='K'||data[pos[2]][pos[3]][0]=='Q')){
            if(((abs(pos[3]-pos[1])==2)&&(abs(pos[2]-pos[0])==1))||(abs(pos[3]-pos[1])==1)&&(abs(pos[2]-pos[0])==2)){
                if(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='P'||data[pos[2]][pos[3]][0]=='Q'||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'||data[pos[2]][pos[3]][0]=='K'||data[pos[2]][pos[3]][0]=='N'){
                    if(update==1){
                    data[pos[2]][pos[3]][0]='n';
                    data[pos[0]][pos[1]][0]=' ';
                    if(render==1){
                    bcolor(pos[0],pos[1]);
                    emptyren(pos[0],pos[1]);
                    bcolor(pos[2],pos[3]);
                    knightren(pos[2],pos[3]);
                    }}
                    return 1;
                }
            }
            return 0;
        }
        else if(data[pos[0]][pos[1]][0]=='k'&&(data[pos[2]][pos[3]][0]==' '||data[pos[2]][pos[3]][0]=='R'||data[pos[2]][pos[3]][0]=='B'||data[pos[2]][pos[3]][0]=='N'||data[pos[2]][pos[3]][0]=='P'||data[pos[2]][pos[3]][0]=='K'||data[pos[2]][pos[3]][0]=='Q')){
            if(((data[pos[0]][pos[1]][0]==data[pos[2]-1][pos[3]][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]-1][pos[3]-1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]-1][pos[3]+1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]][pos[3]-1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]][pos[3]+1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]+1][pos[3]][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]+1][pos[3]-1][0]) || (data[pos[0]][pos[1]][0]==data[pos[2]+1][pos[3]+1][0])) && ((data[pos[2]][pos[3]][0]==' ')||(data[pos[2]][pos[3]][0]=='K')||(data[pos[2]][pos[3]][0]=='Q')||(data[pos[2]][pos[3]][0]=='P')||(data[pos[2]][pos[3]][0]=='R')||(data[pos[2]][pos[3]][0]=='B')||(data[pos[2]][pos[3]][0]=='N'))){
                if(update==1){
                data[pos[2]][pos[3]][0]='k';
                data[pos[0]][pos[1]][0]=' ';
                if(pos[0]==0&&pos[1]==4){
                    data[0][4][1]=' ';
                }
                if(render==1){
                bcolor(pos[0],pos[1]);
                emptyren(pos[0],pos[1]);
                bcolor(pos[2],pos[3]);
                kingren(pos[2],pos[3]);
                }}
                return 1;
            }
            else
            return 0;
        }
        else if(data[pos[0]][pos[1]][0]=='k'&&data[pos[2]][pos[3]][0]=='r'&&data[pos[0]][pos[1]][1]=='C'&&data[pos[2]][pos[3]][1]=='C'){
            int p[4]={pos[2],pos[3],pos[0],pos[1]};
            int r=rpath(data,p);
            if (r==1){
                if(pos[1]<pos[3]){
                    if(update==1){
                    data[pos[0]][pos[1]][0]=' ';
                    data[pos[2]][pos[3]][0]=' ';
                    data[pos[0]][pos[1]][1]=' ';
                    data[pos[2]][pos[3]][1]=' ';
                    data[pos[0]][pos[1]+2][0]='k';
                    data[pos[0]][pos[1]+1][0]='r';
                    if(render==1){
                    bcolor(pos[0],pos[1]);
                    emptyren(pos[0],pos[1]);
                    bcolor(pos[2],pos[3]);
                    emptyren(pos[2],pos[3]);
                    bcolor(pos[0],pos[1]+2);
                    kingren(pos[0],pos[1]+2);
                    bcolor(pos[0],pos[1]+1);
                    rookren(pos[0],pos[1]+1);
                    }}
                    return 1;
                }
                else if(pos[1]>pos[3]){
                    if(update==1){
                    data[pos[0]][pos[1]][0]=' ';
                    data[pos[2]][pos[3]][0]=' ';
                    data[pos[0]][pos[1]][1]=' ';
                    data[pos[2]][pos[3]][1]=' ';
                    data[pos[0]][pos[1]-2][0]='k';
                    data[pos[0]][pos[1]-1][0]='r';
                    if(render==1){
                    bcolor(pos[0],pos[1]);
                    emptyren(pos[0],pos[1]);
                    bcolor(pos[2],pos[3]);
                    emptyren(pos[2],pos[3]);
                    bcolor(pos[0],pos[1]-2);
                    kingren(pos[0],pos[1]-2);
                    bcolor(pos[0],pos[1]-1);
                    rookren(pos[0],pos[1]-1);
                    }}
                    return 1;
                }
            }
            else{
                return 0;
            }
        }
        return 0;
    }
}   