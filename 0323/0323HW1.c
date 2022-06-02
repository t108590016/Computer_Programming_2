#include <stdio.h>
#include <string.h>
//注意什麼時候判斷要不要牌

float count_score(char score[3]){
    if(score[0]=='1')
        return 10;
    else if(score[0]=='J'||score[0]=='Q'||score[0]=='K')
        return 0.5;
    else if(score[0]=='A')
        return 1;
    else
        return (int)score[0]-48;
}

int main(){
    char player[3],computer[3],player_YorN='Y',computer_YorN='Y',player_have_N='N',computer_have_N='N';
    float score_player=0,score_computer=0;
    while(player_YorN=='Y' || computer_YorN=='Y'){
        if(player_YorN=='Y' && player_have_N=='N'){
            scanf("%s",&player);
            score_player+=count_score(player);
        }
        if(computer_YorN=='Y' && computer_have_N=='N'){
            scanf("%s",&computer);
            score_computer+=count_score(computer);
        }
        if(player_YorN=='Y' && player_have_N=='N')
            scanf("%s",&player_YorN);
        if(player_YorN=='N')
            player_have_N='Y';
        if(((score_computer<score_player) || (score_computer<=8.0)) && computer_have_N=='N')
            computer_YorN='Y';
        else{
            computer_YorN='N';
            computer_have_N='Y';
        }
        if(score_player>10.5){
            score_player=0;
            player_YorN='N';
            player_have_N='Y';
        }
        if(score_computer>10.5){
            score_computer=0;
            computer_YorN='N';
            computer_have_N='Y';
        }
    }
    printf("%.1f vs. %.1f\n",score_player,score_computer);
    if((10.5-score_player)<(10.5-score_computer))
        printf("player wins");
    else if((10.5-score_player)>(10.5-score_computer))
        printf("computer wins");
    else
        printf("It's a tie");
    return 0;
}


