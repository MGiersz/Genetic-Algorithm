
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#define population  1000
#define length_of_path  100
#define num_of_doors 5
int results[population][length_of_path];
int children[population][length_of_path];
int path[length_of_path][num_of_doors];
int counter_of_coins[population];
int mutation = 5;
int count_of_ones[length_of_path];
int szopus = 0;

#define RED_TEXT "\033[1;31m"
#define RESET_COLOR "\033[0m"

void random_path() {
    for (int i = 0; i < length_of_path; i++) {
        for (int j = 0; j < num_of_doors; j++) {
            int coin = rand() % 100 + 1;
            if (coin <= 40) {
                path[i][j] = 1;
                count_of_ones[i] = 1;
            }
            else
                path[i][j] = 0;
        }
    }
    for (int i = 0; i < length_of_path; i++) {
        if (count_of_ones[i] == 1)
            szopus++;
    }
    std::cout << szopus << std::endl;
}
void show_path() {
    std::cout << std::endl;
    for (int i = 0; i < length_of_path; i++) {
        for (int j = 0; j < num_of_doors; j++) {
            if (results[population - 1][i] == j)
                std::cout << RED_TEXT << path[i][j] << RESET_COLOR " ";
            else
                std::cout << path[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
/*void show_path() {
    std::cout << std::endl;
    for (int i = 0; i < num_of_doors; i++) {
        for (int j = 0; j < length_of_path; j++) {
            if (results[population - 1][j] == i)
                std::cout << RED_TEXT << path[i][j] << RESET_COLOR " ";
            else
                std::cout << path[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}*/
void random_results() {
    for (int i = 0; i < population; i++) {
        for (int j = 0; j < length_of_path; j++) {
            int coin = rand() % num_of_doors;
            results[i][j] = coin;
        }
    }
}
void show_results() {
    for (int i = 0; i < population; i++) {
        for (int j = 0; j < length_of_path; j++) {
            std::cout << results[i][j] + 1 << " ";
        }
        std::cout << std::endl;
    }
}
void count_coins() {
    for (int i = 0; i < population; i++) {
        counter_of_coins[i] = 0;
        for (int j = 0; j < length_of_path; j++) {
            if (path[j][results[i][j]] == 1) {
                counter_of_coins[i]++;
            }
        }
    }
}
void bubble_sort() {
    for (int i = 0; i < population; i++) {
        for (int j = 0; j < population - 1; j++) {
            if (counter_of_coins[j] >= counter_of_coins[j + 1]) {
                std::swap(counter_of_coins[j], counter_of_coins[j + 1]);
                for (int k = 0; k < length_of_path; k++) {
                    std::swap(results[j][k], results[j + 1][k]);
                }
            }
        }
    }
}
void multiplication() {
    int how_many = population / 2;
    for (int i = 0; i < population - 10; i++) {

        int p1 = rand() % population / 2 + how_many;
        int p2, parent;
        do {
            p2 = rand() % population / 2 + how_many;
        } while (p2 == p1);

        for (int j = 0; j < length_of_path; j++) {
            int random = rand() % 2;
            if (random == 0)
                parent = p1;
            else
                parent = p2;
            //std::cout<< parent+1 << " ";
            children[i][j] = results[parent][j];
        }
        //std::cout << std::endl;
        /*for (int j = 0; j < length_of_path; j++) {

            std::cout << children[0][j]+1 << " ";

        }*/
    }


    for (int i = 0; i < population - 10; i++) {
        for (int j = 0; j < length_of_path; j++) {
            results[i][j] = children[i][j];
            /*int coin = rand() % 100 + 1;
            int coin2;
            if (coin <= mutation) {
                do {
                    coin2 = rand() % num_of_doors;
                } while (coin2 == results[i][j]);
                results[i][j] = coin2;
            }*/
        }
    }


}

void genetic_algorithm() {
    random_results();
    while (counter_of_coins[population - 1] < szopus) {

        //show_results();
        count_coins();
        bubble_sort();
        std::cout << std::endl << counter_of_coins[population - 1];
        show_path();
        multiplication();
    }
    std::cout << std::endl << "Path: ";
    for (int i = 0; i < length_of_path; i++)
        std::cout << results[population - 1][i] + 1;



}


int main()
{
    srand(time(0));


    random_path();
    //show_path();

    genetic_algorithm();



}


















