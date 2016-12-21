#include <stdio.h>
#include <string.h> //memset library

char grid[3][3]; //2D Array

void print_game() {
	printf("\n %c | %c | %c \n", grid[0][0], grid[0][1], grid[0][2] );
	printf("-----------\n");
	printf(" %c | %c | %c \n", grid[1][0], grid[1][1], grid[1][2] );
	printf("-----------\n");
	printf(" %c | %c | %c \n", grid[2][0], grid[2][1], grid[2][2] );
}

int has_won(){
	//column 1
	if((grid[0][0] == grid[1][0]) && (grid[0][0] == grid[2][0]) && grid[0][0] != ' '){
		return 1;
	}
	//column 2
	else if((grid[0][1] == grid[1][1]) && (grid[0][1] == grid[2][1]) && grid[0][1] != ' '){
		return 1;
	}
	//column 3
	else if((grid[0][2] == grid[1][2]) && (grid[0][2] == grid[2][2]) && grid[0][2] != ' '){
		return 1;
	}
	//row 1
	else if((grid[0][0] == grid[0][1]) && (grid[0][0] == grid[0][2]) && grid[0][0] != ' '){
		return 1;
	}
	//row 2
	else if((grid[1][0] == grid[1][1]) && (grid[1][0] == grid[1][2]) && grid[1][0] != ' '){
		return 1;
	}
	//row 3
	else if((grid[2][0] == grid[2][1]) && (grid[2][0] == grid[2][2]) && grid[2][0] != ' '){
		return 1;
	}
	
	//diagonal left to right
	else if((grid[0][0] == grid[1][1]) && (grid[0][0] == grid[2][2]) && grid[0][0] != ' '){
		return 1;
	}
	//diagonal right to left
	else if((grid[0][2] == grid[1][1]) && (grid[0][2] == grid[2][0]) && grid[0][2] != ' '){
		return 1;
	}
	
	return 0;
	
}

int is_draw() {
	if(grid[0][0] != ' ' && grid[1][0] != ' ' && grid[2][0] != ' ' && grid[0][1] != ' ' 
		&& grid[1][1] != ' ' && grid[2][1] != ' ' && grid[0][2] != ' ' && grid[1][2] != ' ' && grid[2][2] != ' ') {
		return 1;
		}
		return 0;
}


int main(){
			
	memset(grid, ' ', sizeof(grid)); //instead of using for loops
	
	while(1){
		int x, y;
		
		/*PLAYER 1*/
		printf("\nPlayer 1 Enter coordinates :");
		scanf("%i %i", &x, &y);
		
		while(grid[x][y] != ' '){
			printf("Taken. Enter new coordinates:");
			scanf("%i %i", &x, &y);
		}
		
		grid[x][y] = 'O';
		print_game();
		
		if(has_won()){
			printf("Player 1 has won!\n");
			return 0;
		}
		
		if(is_draw()){
			printf("Draw");
			return 0;
		}
		
		/*PLAYER 2*/
		printf("\nPlayer 2 Enter coordinates :");
		scanf("%i %i", &x, &y);
	
		while(grid[x][y] != ' '){
			printf("Taken. Enter new coordinates:");
			scanf("%i %i", &x, &y);
		}
		
		grid[x][y] = 'X';
		print_game();
		
		if(has_won()){
			printf("Player 2 has won!\n");
			return 0;
		}
	}
}
