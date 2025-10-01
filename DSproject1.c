#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Movie
{
    char name[50];
    char genre[20];
    float rating;
    struct Movie* next;
};


struct Series
{
    char name[50];
    char genre[20];
    float rating;
    struct Series* next;
};


struct Movie* MovieNode(char name[], char genre[], float rating);
struct Series* SeriesNode(char name[], char genre[], float rating);
void addMovie(struct Movie* hashTable[], int tableSize, char name[], char genre[], float rating);
void addSeries(struct Series* hashTable[], int tableSize, char name[], char genre[], float rating);
void movieRecommend(struct Movie* hashTable[], int tableSize, char userGenre[], float userRating);
void seriesRecommend(struct Series* hashTable[], int tableSize, char userGenre[], float userRating);
int hashFunction(char key[], int tableSize);


struct Movie* MovieNode(char name[], char genre[], float rating)
{
    struct Movie* newNode = (struct Movie*)malloc(sizeof(struct Movie));
    strcpy(newNode->name, name);
    strcpy(newNode->genre, genre);
    newNode->rating = rating;
    newNode->next = NULL;
    return newNode;
}


struct Series* SeriesNode(char name[], char genre[], float rating)
{
    struct Series* newNode = (struct Series*)malloc(sizeof(struct Series));
    strcpy(newNode->name, name);
    strcpy(newNode->genre, genre);
    newNode->rating = rating;
    newNode->next = NULL;
    return newNode;
}


void addMovie(struct Movie* hashTable[], int tableSize, char name[], char genre[], float rating)
{
    struct Movie* newMovie = MovieNode(name, genre, rating);
    int hashValue = hashFunction(newMovie->genre, tableSize);
    newMovie->next = hashTable[hashValue];
    hashTable[hashValue] = newMovie;
}


void addSeries(struct Series* hashTable[], int tableSize, char name[], char genre[], float rating)
{
    struct Series* newSeries = SeriesNode(name, genre, rating);
    int hashValue = hashFunction(newSeries->genre, tableSize);
    newSeries->next = hashTable[hashValue];
    hashTable[hashValue] = newSeries;
}

void movieRecommend(struct Movie* hashTable[], int tableSize, char userGenre[], float userRating)
{
    printf("Recommended movies in the %s genre with a rating of %.1f or higher:\n", userGenre, userRating);

    int hashValue = hashFunction(userGenre, tableSize);
    struct Movie* current = hashTable[hashValue];

    int found = 0;

    while (current != NULL)
    {
        if (strcmp(current->genre, userGenre) == 0 && current->rating >= userRating)
        {
            printf("- %s (Rating: %.1f)\n", current->name, current->rating);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
    {
        printf("No movies match the given criteria.\n");
    }
}


void seriesRecommend(struct Series* hashTable[], int tableSize, char userGenre[], float userRating)
{
    printf("\nRecommended series in the %s genre with a rating of %.1f or higher:\n", userGenre, userRating);

    int hashValue = hashFunction(userGenre, tableSize);
    struct Series* current = hashTable[hashValue];

    int found = 0;

    while (current != NULL)
    {
        if (strcmp(current->genre, userGenre) == 0 && current->rating >= userRating)
        {
            printf("- %s (Rating: %.1f)\n", current->name, current->rating);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
    {
        printf("No series match the given criteria.\n");
    }
}


int hashFunction(char key[], int tableSize)
{
    int hashValue = 0;
    for (int i = 0; i < strlen(key); ++i)
    {
        hashValue += key[i];
    }
    return hashValue % tableSize;
}

int main()
{

    const int tableSize = 10;


    struct Movie* movieHashTable[tableSize];
    struct Series* seriesHashTable[tableSize];

    for (int i = 0; i < tableSize; ++i)
    {
        movieHashTable[i] = NULL;
        seriesHashTable[i] = NULL;
    }
    addMovie(movieHashTable, tableSize, "Avengers", "Action", 4.5);
    addMovie(movieHashTable, tableSize, "The Marvels", "Action", 3.8);
    addMovie(movieHashTable, tableSize, "The Killer", "Action", 3.5);
    addMovie(movieHashTable, tableSize, "Tiger 3", "Action", 3.5);
    addMovie(movieHashTable, tableSize, "War", "Action", 3.8);
    addMovie(movieHashTable, tableSize, "Brothers", "Action", 3.5);
    addMovie(movieHashTable, tableSize, "Pathan", "Action", 3.8);
    addMovie(movieHashTable, tableSize, "Gumraah", "Action", 3.8);
    addMovie(movieHashTable, tableSize, "Kuttey", "Action", 3.8);
    addMovie(movieHashTable, tableSize, "RRR", "Action", 4.5);
    addMovie(movieHashTable, tableSize, "Top Gun", "Action", 3.4);
    addMovie(movieHashTable, tableSize, "The Flash", "Action", 4.6);
    addMovie(movieHashTable, tableSize, "The Mother", "Action", 4.7);
    addMovie(movieHashTable, tableSize, "Jawan", "Action", 4.8);
    addMovie(movieHashTable, tableSize, "Napoleon", "Action", 4.5);
    addMovie(movieHashTable, tableSize, "Invincible", "Action", 4.5);
    addMovie(movieHashTable, tableSize, "Avengers", "Action", 4.5);
    addMovie(movieHashTable, tableSize, "Venom", "Action", 4.5);
    addMovie(movieHashTable, tableSize, "Hunger Games", "Action", 4.2);
    addMovie(movieHashTable, tableSize, "John Wick", "Action", 4.0);
    addMovie(movieHashTable, tableSize, "Batman", "Action", 3.5);
    addMovie(movieHashTable, tableSize, "Spiderman", "Action", 4.1);
    addMovie(movieHashTable, tableSize, "The Dark Knight", "Action", 3.9);
    addMovie(movieHashTable, tableSize, "Blade Runner", "Action", 4.4);
    addMovie(movieHashTable, tableSize, "Suicide Squad", "Action", 3.7);
    addMovie(movieHashTable, tableSize, "Leon", "Action", 4.2);

    addMovie(movieHashTable, tableSize, "Jagga Jasoos", "Adventure", 4.8);
    addMovie(movieHashTable, tableSize, "Ram Setu", "Adventure", 4.8);
    addMovie(movieHashTable, tableSize, "65", "Adventure", 4.8);
    addMovie(movieHashTable, tableSize, "The Lost City", "Adventure", 4.8);
    addMovie(movieHashTable, tableSize, "The Monkey King", "Adventure", 4.8);
    addMovie(movieHashTable, tableSize, "Zindegi Na Milegi Dobara", "Adventure", 4.5);
    addMovie(movieHashTable, tableSize, "Coco", "Adventure", 4.5);
    addMovie(movieHashTable, tableSize, "Aliens", "Adventure", 4.5);
    addMovie(movieHashTable, tableSize, "Spirited Away", "Adventure", 4.5);
    addMovie(movieHashTable, tableSize, "The Lion King", "Adventure", 4.5);
    addMovie(movieHashTable, tableSize, "Back To The Future", "Adventure", 4.5);
    addMovie(movieHashTable, tableSize, "Inside Out", "Adventure", 3.5);
    addMovie(movieHashTable, tableSize, "Barbie", "Adventure", 4.0);
    addMovie(movieHashTable, tableSize, "Wonka", "Adventure", 4.0);
    addMovie(movieHashTable, tableSize, "Little Mermaid", "Adventure", 4.2);

    addMovie(movieHashTable, tableSize, "Madagascar", "Animation", 4.2);
    addMovie(movieHashTable, tableSize, "Despicable Me", "Animation", 4.2);
    addMovie(movieHashTable, tableSize, "Moana", "Animation", 4.2);
    addMovie(movieHashTable, tableSize, "Your Name", "Animation", 4.5);
    addMovie(movieHashTable, tableSize, "Snow White", "Animation", 4.5);
    addMovie(movieHashTable, tableSize, "Aladdin", "Animation", 4.5);
    addMovie(movieHashTable, tableSize, "Grave of the Fireflies", "Animation", 4.0);
    addMovie(movieHashTable, tableSize, "My Neighbor Totoro", "Animation", 4.0);
    addMovie(movieHashTable, tableSize, "Up!", "Animation", 4.0);
    addMovie(movieHashTable, tableSize, "Inside Out", "Animation", 4.0);

    addMovie(movieHashTable, tableSize, "Hera Pheri", "Comedy", 4.2);
    addMovie(movieHashTable, tableSize, "De Dana Dan", "Comedy", 4.2);
    addMovie(movieHashTable, tableSize, "3 idiots", "Comedy", 4.2);
    addMovie(movieHashTable, tableSize, "Dhamal", "Comedy", 4.0);
    addMovie(movieHashTable, tableSize, "Golmaal 3", "Comedy", 4.0);
    addMovie(movieHashTable, tableSize, "Entertainment", "Comedy", 4.0);
    addMovie(movieHashTable, tableSize, "Welcome", "Comedy", 4.5);
    addMovie(movieHashTable, tableSize, "Cirkus", "Comedy", 4.5);
    addMovie(movieHashTable, tableSize, "Housefull 3", "Comedy", 4.8);
    addMovie(movieHashTable, tableSize, "Bol Bachchan", "Comedy", 4.6);
    addMovie(movieHashTable, tableSize, "Kathal", "Comedy", 4.8);
    addMovie(movieHashTable, tableSize, "Barfi", "Comedy", 4.8);

    addMovie(movieHashTable, tableSize, "Raees", "Crime", 4.0);
    addMovie(movieHashTable, tableSize, "Gunday", "Crime", 4.0);
    addMovie(movieHashTable, tableSize, "Mardaani", "Crime", 4.0);
    addMovie(movieHashTable, tableSize, "Gumraah", "Crime", 4.0);
    addMovie(movieHashTable, tableSize, "The Killer", "Crime", 4.2);
    addMovie(movieHashTable, tableSize, "Article 15", "Crime", 4.2);
    addMovie(movieHashTable, tableSize, "Drishyam 2", "Crime", 4.2);
    addMovie(movieHashTable, tableSize, "V", "Crime", 4.5);
    addMovie(movieHashTable, tableSize, "Soni", "Crime", 4.5);
    addMovie(movieHashTable, tableSize, "Talvar", "Crime", 4.5);
    addMovie(movieHashTable, tableSize, "Sinam", "Crime", 4.5);
    addMovie(movieHashTable, tableSize, "Believer 2", "Crime", 3.2);
    addMovie(movieHashTable, tableSize, "Neeyat", "Crime", 3.5);
    addMovie(movieHashTable, tableSize, "Red", "Crime", 3.2);

    addMovie(movieHashTable, tableSize, "OMG 2", "Drama", 4.8);
    addMovie(movieHashTable, tableSize, "The Killer", "Drama", 4.8);
    addMovie(movieHashTable, tableSize, "Dear Zindegi", "Drama", 4.8);
    addMovie(movieHashTable, tableSize, "Udaan", "Drama", 4.8);
    addMovie(movieHashTable, tableSize, "Nowhere", "Drama", 4.7);
    addMovie(movieHashTable, tableSize, "Kabhi kushi kabhi gham", "Drama", 4.9);
    addMovie(movieHashTable, tableSize, "Jalsa", "Drama", 4.4);
    addMovie(movieHashTable, tableSize, "Section 375", "Drama", 4.2);
    addMovie(movieHashTable, tableSize, "Rustin", "Drama", 4.5);
    addMovie(movieHashTable, tableSize, "Sukhee", "Drama", 4.2);
    addMovie(movieHashTable, tableSize, "Bro", "Drama", 4.2);
    addMovie(movieHashTable, tableSize, "Gumraah", "Drama", 4.0);

    addMovie(movieHashTable, tableSize, "Paheli", "Fantasy", 4.0);
    addMovie(movieHashTable, tableSize, "Tumbbad", "Fantasy", 4.0);
    addMovie(movieHashTable, tableSize, "Baahubali 2", "Fantasy", 4.5);
    addMovie(movieHashTable, tableSize, "Golmaal Again", "Fantasy", 4.5);
    addMovie(movieHashTable, tableSize, "Adipurush", "Fantasy", 4.5);
    addMovie(movieHashTable, tableSize, "Troll", "Fantasy", 3.2);
    addMovie(movieHashTable, tableSize, "Monster Hunter", "Fantasy", 3.2);
    addMovie(movieHashTable, tableSize, "King Kong", "Fantasy", 4.9);
    addMovie(movieHashTable, tableSize, "Black Panther", "Fantasy", 4.8);
    addMovie(movieHashTable, tableSize, "The Avengers", "Fantasy", 4.8);

    addMovie(movieHashTable, tableSize, "Bulbbul", "Horror", 4.9);
    addMovie(movieHashTable, tableSize, "1921", "Horror", 4.9);
    addMovie(movieHashTable, tableSize, "Stree", "Horror", 4.8);
    addMovie(movieHashTable, tableSize, "Bhool Bhulaiyaa 2", "Horror", 4.7);
    addMovie(movieHashTable, tableSize, "Pari", "Horror", 4.0);
    addMovie(movieHashTable, tableSize, "Sewu Dino", "Horror", 4.2);
    addMovie(movieHashTable, tableSize, "The Nun", "Horror", 4.8);
    addMovie(movieHashTable, tableSize, "Sister Death", "Horror", 4.2);
    addMovie(movieHashTable, tableSize, "The Invitation", "Horror", 4.2);
    addMovie(movieHashTable, tableSize, "The Ritual", "Horror", 4.0);
    addMovie(movieHashTable, tableSize, "Alive", "Horror", 4.8);
    addMovie(movieHashTable, tableSize, "The Conference", "Horror", 4.0);
    addMovie(movieHashTable, tableSize, "Insidious", "Horror", 3.2);
    addMovie(movieHashTable, tableSize, "Spirit Doll", "Horror", 3.5);
    addMovie(movieHashTable, tableSize, "Qorin", "Horror", 3.0);
    addMovie(movieHashTable, tableSize, "Creep", "Horror", 3.2);

    addMovie(movieHashTable, tableSize, "Talash", "Mystery", 4.3);
    addMovie(movieHashTable, tableSize, "The Body", "Mystery", 4.6);
    addMovie(movieHashTable, tableSize, "Jagga Jasoos", "Mystery", 4.5);
    addMovie(movieHashTable, tableSize, "Khufiya", "Mystery", 4.5);
    addMovie(movieHashTable, tableSize, "Dobaaraa", "Mystery", 4.5);
    addMovie(movieHashTable, tableSize, "Jaane Jaan", "Mystery", 4.5);
    addMovie(movieHashTable, tableSize, "Neeyat", "Mystery", 4.1);
    addMovie(movieHashTable, tableSize, "Badla", "Mystery", 4.0);
    addMovie(movieHashTable, tableSize, "Kolai", "Mystery", 4.0);
    addMovie(movieHashTable, tableSize, "The 8th Night", "Mystery", 3.2);
    addMovie(movieHashTable, tableSize, "Shutter", "Mystery", 2.2);
    addMovie(movieHashTable, tableSize, "Aapla Manus", "Mystery", 3.2);

    addMovie(movieHashTable, tableSize, "Bawaal", "Romance", 4.8);
    addMovie(movieHashTable, tableSize, "Rocky Aur Rani", "Romance", 4.8);
    addMovie(movieHashTable, tableSize, "Kushi", "Romance", 4.8);
    addMovie(movieHashTable, tableSize, "Kalank", "Romance", 4.0);
    addMovie(movieHashTable, tableSize, "Mohabbatein", "Romance", 4.9);
    addMovie(movieHashTable, tableSize, "Ocean Waves", "Romance", 4.5);
    addMovie(movieHashTable, tableSize, "Khoobsurat", "Romance", 4.5);
    addMovie(movieHashTable, tableSize, "See you on Venus", "Romance", 4.3);
    addMovie(movieHashTable, tableSize, "Student of the Year", "Romance", 4.2);
    addMovie(movieHashTable, tableSize, "18 Pages", "Romance", 4.2);

    addMovie(movieHashTable, tableSize, "2.0", "Sci-fi", 4.0);
    addMovie(movieHashTable, tableSize, "PK", "Sci-fi", 4.2);
    addMovie(movieHashTable, tableSize, "Lucy", "Sci-fi", 4.2);
    addMovie(movieHashTable, tableSize, "Project Power", "Sci-fi", 4.0);
    addMovie(movieHashTable, tableSize, "Palm Springs", "Sci-fi", 4.2);
    addMovie(movieHashTable, tableSize, "Cargo", "Sci-fi", 4.5);
    addMovie(movieHashTable, tableSize, "Space Jam", "Sci-fi", 4.5);
    addMovie(movieHashTable, tableSize, "Castle in the Sky", "Sci-fi", 4.8);

    addMovie(movieHashTable, tableSize, "Raazi", "Thriller", 4.0);
    addMovie(movieHashTable, tableSize, "War", "Thriller", 4.5);
    addMovie(movieHashTable, tableSize, "Mirrors", "Thriller", 4.2);
    addMovie(movieHashTable, tableSize, "The Killer", "Thriller", 4.0);
    addMovie(movieHashTable, tableSize, "Pathaan", "Thriller", 4.0);
    addMovie(movieHashTable, tableSize, "Runway 34", "Thriller", 3.2);
    addMovie(movieHashTable, tableSize, "Talash", "Thriller", 3.0);
    addMovie(movieHashTable, tableSize, "Madras Cafe", "Thriller", 3.5);
    addMovie(movieHashTable, tableSize, "Inferno", "Thriller", 3.5);
    addMovie(movieHashTable, tableSize, "65", "Thriller", 4.8);
    addMovie(movieHashTable, tableSize, "Fair Play", "Thriller", 4.8);






     addSeries(seriesHashTable, tableSize, "Stranger Things", "Sci-Fi", 4.8);
     addSeries(seriesHashTable, tableSize, "Loki", "Sci-fi", 4.1);
     addSeries(seriesHashTable, tableSize,"Rick and Morty", "Sci-fi", 4.2);
     addSeries(seriesHashTable, tableSize, "Monarch", "Sci-fi", 4.5);
     addSeries(seriesHashTable, tableSize, "For All Mankind", "Sci-fi", 4.5);
     addSeries(seriesHashTable, tableSize, "Doctor Who", "Sci-fi", 4.0);
     addSeries(seriesHashTable, tableSize, "Upload", "Sci-fi", 4.0);
     addSeries(seriesHashTable, tableSize, "Beacon 23", "Sci-fi", 3.0);

     addSeries(seriesHashTable, tableSize, "Friends", "Comedy", 4.8);
     addSeries(seriesHashTable, tableSize, "Business Proposal", "Comedy", 4.8);
     addSeries(seriesHashTable, tableSize, "Happy family", "Comedy", 4.5);
     addSeries(seriesHashTable, tableSize, "Never Have I Ever", "Comedy", 4.5);
     addSeries(seriesHashTable, tableSize, "Bloodhounds", "Comedy", 4.5);
     addSeries(seriesHashTable, tableSize, "Mismatched", "Comedy", 4.9);
     addSeries(seriesHashTable, tableSize, "Upload", "Comedy", 3.5);
     addSeries(seriesHashTable, tableSize, "True Beauty", "Comedy", 4.0);
     addSeries(seriesHashTable, tableSize, "It's Okey To Not Be Okey", "Comedy", 4.8);
     addSeries(seriesHashTable, tableSize, "Guns & Gulaabs", "Comedy", 3.8);
     addSeries(seriesHashTable, tableSize, "Fuller House", "Comedy", 4.0);

     addSeries(seriesHashTable, tableSize, "Game of Thrones", "Drama", 4.3);
     addSeries(seriesHashTable, tableSize, "Breaking Bad", "Drama", 4.9);
     addSeries(seriesHashTable, tableSize, "Falcon and the Winter Soldier", "Drama", 3.8);
     addSeries(seriesHashTable, tableSize, "Kala Pani", "Drama", 4.3);
     addSeries(seriesHashTable, tableSize, "Castaway Diva", "Drama", 3.3);
     addSeries(seriesHashTable, tableSize, "Vikings", "Drama", 4.3);
     addSeries(seriesHashTable, tableSize, "Dark", "Drama", 4.2);
     addSeries(seriesHashTable, tableSize, "The OA", "Drama", 4.3);
     addSeries(seriesHashTable, tableSize, "Little Women", "Drama", 4.5);
     addSeries(seriesHashTable, tableSize, "The Crown", "Drama", 4.8);
     addSeries(seriesHashTable, tableSize, "Only For Love", "Drama", 4.0);

     addSeries(seriesHashTable, tableSize, "Farzi", "Crime", 4.0);
     addSeries(seriesHashTable, tableSize, "Carnival Row", "Crime", 4.5);
     addSeries(seriesHashTable, tableSize, "Peaky Blinders", "Crime", 4.3);
     addSeries(seriesHashTable, tableSize, "Delhi Crime", "Crime", 3.0);
     addSeries(seriesHashTable, tableSize, "Hunters", "Crime", 4.5);
     addSeries(seriesHashTable, tableSize, "Bodies", "Crime", 4.2);
     addSeries(seriesHashTable, tableSize, "The Blacklist", "Crime", 4.3);

     addSeries(seriesHashTable, tableSize, "Farzi", "Thriller", 4.5);
     addSeries(seriesHashTable, tableSize, "Kaala paani", "Thriller", 4.0);
     addSeries(seriesHashTable, tableSize, "Dahaad", "Thriller", 4.8);
     addSeries(seriesHashTable, tableSize, "Bambai Meri Jaan", "Thriller", 4.2);
     addSeries(seriesHashTable, tableSize, "Adhura", "Thriller", 4.5);
     addSeries(seriesHashTable, tableSize, "The Midnight Club", "Thriller", 4.3);
     addSeries(seriesHashTable, tableSize, "The Family Man", "Thriller", 4.2);
     addSeries(seriesHashTable, tableSize, "The Order", "Thriller", 4.0);

     addSeries(seriesHashTable, tableSize, "The Midnight Club", "Horror", 4.0);
     addSeries(seriesHashTable, tableSize, "Adhura", "Horror", 4.5);
     addSeries(seriesHashTable, tableSize, "Loke & Key", "Horror", 4.8);
     addSeries(seriesHashTable, tableSize, "The Sandman", "Horror", 4.5);
     addSeries(seriesHashTable, tableSize, "Wednesday", "Horror", 3.2);
     addSeries(seriesHashTable, tableSize, "Stranger Things", "Horror", 4.5);
     addSeries(seriesHashTable, tableSize, "Betaal", "Horror", 4.8);
     addSeries(seriesHashTable, tableSize, "Hellbound", "Horror", 4.0);

     addSeries(seriesHashTable, tableSize, "1899", "Mystery", 4.5);
     addSeries(seriesHashTable, tableSize, "A time Called You", "Mystery", 4.8);
     addSeries(seriesHashTable, tableSize, "The Watcher", "Mystery", 4.0);
     addSeries(seriesHashTable, tableSize, "Supernatural", "Mystery", 4.2);
     addSeries(seriesHashTable, tableSize, "Castle Rock", "Mystery", 3.0);
     addSeries(seriesHashTable, tableSize, "Girl From Nowhere", "Mystery", 3.5);
     addSeries(seriesHashTable, tableSize, "Obsession", "Mystery", 4.5);
     addSeries(seriesHashTable, tableSize, "The Tailor", "Mystery", 4.9);
     addSeries(seriesHashTable, tableSize, "Awaken", "Mystery", 4.0);

     addSeries(seriesHashTable, tableSize, "Castaway Diva", "Romance", 4.5);
     addSeries(seriesHashTable, tableSize, "Destined With You", "Romance", 4.5);
     addSeries(seriesHashTable, tableSize, "Doona", "Romance", 4.5);
     addSeries(seriesHashTable, tableSize, "Hidden Love", "Romance", 4.0);
     addSeries(seriesHashTable, tableSize, "Love", "Romance", 4.8);
     addSeries(seriesHashTable, tableSize, "The Office", "Romance", 4.8);
     addSeries(seriesHashTable, tableSize, "At the Moment", "Romance", 4.0);
     addSeries(seriesHashTable, tableSize, "Cheer Up", "Romance", 4.2);
     addSeries(seriesHashTable, tableSize, "Mismatched", "Romance", 4.0);
     addSeries(seriesHashTable, tableSize, "With Love", "Romance", 3.0);

     addSeries(seriesHashTable, tableSize, "The Witcher", "Adventure", 4.5);
     addSeries(seriesHashTable, tableSize, "Sweet Tooth", "Adventure", 4.0);
     addSeries(seriesHashTable, tableSize, "The Continental", "Adventure", 4.5);
     addSeries(seriesHashTable, tableSize, "Fauda", "Adventure", 4.0);
     addSeries(seriesHashTable, tableSize, "Cursed", "Adventure", 4.8);
     addSeries(seriesHashTable, tableSize, "Supernatural", "Adventure", 4.5);
     addSeries(seriesHashTable, tableSize, "Black Knight", "Adventure", 4.2);
     addSeries(seriesHashTable, tableSize, "The Recruit", "Adventure", 4.0);


     addSeries(seriesHashTable, tableSize, "Chhota Bheem", "Animation", 4.0);
     addSeries(seriesHashTable, tableSize, "Arcane", "Animation", 4.0);
     addSeries(seriesHashTable, tableSize, "Fate", "Animation", 4.0);
     addSeries(seriesHashTable, tableSize, "Final Space", "Animation", 4.5);
     addSeries(seriesHashTable, tableSize, "Blood of Zeus", "Animation", 4.5);
     addSeries(seriesHashTable, tableSize, "Zig & Sharko", "Animation", 4.2);
     addSeries(seriesHashTable, tableSize, "Skull Island", "Animation", 3.0);
     addSeries(seriesHashTable, tableSize, "Ben 10", "Animation", 4.8);
     addSeries(seriesHashTable, tableSize, "One Piece", "Animation", 4.5);

     addSeries(seriesHashTable, tableSize, "Island", "Fantasy", 4.2);
     addSeries(seriesHashTable, tableSize, "The Witcher", "Fantasy", 4.5);
     addSeries(seriesHashTable, tableSize, "The King", "Fantasy", 4.5);
     addSeries(seriesHashTable, tableSize, "Ashes of Love", "Fantasy", 3.0);
     addSeries(seriesHashTable, tableSize, "Guardian", "Fantasy", 3.5);
     addSeries(seriesHashTable, tableSize, "The King", "Fantasy", 4.0);
     addSeries(seriesHashTable, tableSize, "Supernatural", "Fantasy", 4.2);
     addSeries(seriesHashTable, tableSize, "Shadowhunters", "Fantasy", 4.5);
     addSeries(seriesHashTable, tableSize, "Destined With You", "Fantasy", 4.0);
     addSeries(seriesHashTable, tableSize, "Alchemy of Souls", "Fantasy", 4.0);
     addSeries(seriesHashTable, tableSize, "Wednesday", "Fantasy", 4.0);

     addSeries(seriesHashTable, tableSize, "Attack on Titan", "Action", 3.8);
     addSeries(seriesHashTable, tableSize, "Invincible", "Action", 3.8);
     addSeries(seriesHashTable, tableSize, "Blue Eye Samurai", "Action", 4.0);
     addSeries(seriesHashTable, tableSize, "My Name", "Action", 3.8);
     addSeries(seriesHashTable, tableSize, "The Boys", "Action", 4.5);
     addSeries(seriesHashTable, tableSize, "Kingdom", "Action", 4.5);
     addSeries(seriesHashTable, tableSize, "Gen V", "Action", 4.8);
     addSeries(seriesHashTable, tableSize, "The Boys", "Action", 3.8);
     addSeries(seriesHashTable, tableSize, "Betaal", "Action", 3.5);
     addSeries(seriesHashTable, tableSize, "Money Heist", "Action", 4.9);


    int option;
    char userGenre[20];
    float userRating;
    char continueSuggestion;




    do{

    printf("************************************************************************************************************************\n");
    printf("******************************** Welcome to Movies & Series Recommendation Program *************************************\n");
    printf("************************************************************************************************************************\n");


    printf("\nOptions:\n\n");
    printf("1. Get Movie Recommendation\n");
    printf("2. Get Series Recommendation\n\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("\nAvailable Genres:\n-Action\n-Adventure\n-Animation\n-Comedy\n-Crime\n-Drama\n-Fantasy\n-Horror\n-Mystery\n-Romance\n-Sci-fi\n-Thriller\n\n");
        printf("Enter the genre for movies: ");
        scanf("%s", userGenre);

        printf("Enter the minimum rating for movies: ");
        scanf("%f", &userRating);


        movieRecommend(movieHashTable, tableSize, userGenre, userRating);
        break;

    case 2:
        printf("\nAvailable Genres:\n-Action\n-Adventure\n-Animation\n-Comedy\n-Crime\n-Drama\n-Fantasy\n-Horror\n-Mystery\n-Romance\n-Sci-fi\n-Thriller\n\n");
        printf("Enter the genre for series: ");
        scanf("%s", userGenre);

        printf("Enter the minimum rating for series: ");
        scanf("%f", &userRating);


        seriesRecommend(seriesHashTable, tableSize, userGenre, userRating);
        break;

    default:
        printf("Invalid option selected.\n");
    }

     printf("\n\nDo you want another suggestion? (y/n): ");
        scanf(" %c", &continueSuggestion);

        printf("\n\n");

    } while (continueSuggestion == 'y' || continueSuggestion == 'Y');

    printf("\n**********  Thank you for using the recommendation program. Have a nice day!  **********\n\n");



    return 0;
}
