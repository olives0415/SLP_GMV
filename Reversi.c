#include<stdio.h>

#define BOARD_SIZE 8

typedef enum {WHT=-1, EMP=0, BLK=1, OUT=2} Piece;

void Board_Init(void);          //�Ֆʂ̏�����
void Board_Output(void);        //�Ֆʂ̏o��
void Board_Scan_Pass(int player);    //�p�X�̗L������
void Board_Input(int player);   //���͏���
int Board_Suffice(void);        //�Ֆʂ��S�Ė��܂������ǂ����̔���
void Game_Finish(void);         //�Q�[���I��


Piece board[BOARD_SIZE][BOARD_SIZE];



//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
//���C���֐�
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
int main(void){
    int player = BLK;
    
    //int n = 0;  //���͂�r���ŏI��������ϐ�
    
    Board_Init();
    Board_Output();
    
    while(1){
        
        switch(player){
            case BLK : printf("���̔Ԃł��B\n"); break;
            case WHT : printf("���̔Ԃł��B\n"); break;
        }
        
        Board_Input(player);
        Board_Output();
        
        if( Board_Suffice() == 0 ){       //�Q�[���I������(�Ֆʂ��S�Ė��܂���)
            
            break;
        }
        
        player *= -1;
        
        //if( n++ == 3 ) break;   //3��ŏI��
    }
    return 0;
}



//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
//�Ֆʂ̏�����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
void Board_Init(void){
    int i, j;
    for( i = 0; i < BOARD_SIZE; i++ ){
        for( j = 0; j < BOARD_SIZE; j++ ){
            board[i][j] = EMP;
        }
    }
    board[3][3] = board[4][4] = BLK;
    board[3][4] = board[4][3] = WHT;
}



//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
//�Ֆʂ̏o��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
void Board_Output(void){
    int i, j;
    
    printf("  Y1Y2Y3Y4Y5Y6Y7Y8\n");
    for( i = 0; i < 8; i++ ){
        printf("X%d",i+1);
        for( j = 0; j < 8; j++ ){
            switch(board[i][j]){
                case EMP: printf("�E"); break;
                case BLK: printf("��"); break;
                case WHT: printf("��"); break;
            }
        }
        puts("");
    }
}



//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
//�p�X�̗L������
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
void Board_Scan_Pass(int player){
    
}



//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
//���͏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
void Board_Input(int player){
    int x, y;
    while(1){
        printf("X > "); scanf("%d", &x); x--;
        printf("Y > "); scanf("%d", &y); y--;
        if( x >= 0 && x < 8 && y >= 0 && y < 8 ){
            if( board[x][y] == EMP ) break;
        }
        printf("\a�����ɂ͒u���܂���I\n");
    }
    board[x][y] = player;
}



//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
//�Ֆʂ��S�Ė��܂������ǂ����̔���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
int Board_Suffice(void){
    int i, j;
    int f = 0;
    
    for( i = 0; i < BOARD_SIZE; i++ ){
        for( j = 0; j < BOARD_SIZE; j++ ){
            if( board[i][j] == EMP ) f = 1;
        }
    }
    
    
    return f;
}



//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
//�Q�[���I������
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|
void Game_Finish(void){
    int b = w = 0;
    int i, j;
    for( i = 0; i < BOARD_SIZE; i++ ){
        for( j = 0; j < BOARD_SIZE; j++ ){
            switch( board[i][j] ){
            case BLK: b += 1; break;
            case WHT: w += 1; break;
            }
        }
    }
    printf("���F%d  ���F%d\n");
    if( b > w )         printf("���̏����ł��I\n");
    else if( b < w )    printf("���̏����ł��I\n");
    else                printf("��������\n");
}
