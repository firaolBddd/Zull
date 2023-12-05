#include <vector>
#include <cstring>
#include "dmedia.h"
#include "movies.h"
#include "music.h"
#include "vgames.h"

using namespace std;

// Function to add a media item to the storage
void addMedia(vector<dmedia*>& storage) {
    cout << "Choose media type to add (1. Movie, 2. Music, 3. Video Game): ";
    int mediaType;
    cin >> mediaType;
    cin.ignore();

    dmedia* newMedia;

    switch (mediaType) {
        case 1:
            newMedia = new movies();
            break;
        case 2:
            newMedia = new music();
            break;
        case 3:
            newMedia = new vgames();
            break;
        default:
            cout << "Invalid media type." << endl;
            return;
    }

    // Set common details of the media item
    cout << "Enter Title: ";
    cin >> newMedia->getTitle();
    cin.ignore();

    cout << "Enter Year: ";
    cin >> *newMedia->getYear();
    cin.ignore();

    // Set additional details based on the type
    if (mediaType == 1) {  // Movie
        movies* mv = dynamic_cast<movies*>(newMedia);
        cout << "Enter Director: ";
        cin >> mv->getDirector();
        cin.ignore();

        cout << "Enter Duration: ";
        cin >> *mv->getDuration();
        cin.ignore();

        cout << "Enter Rating: ";
        cin >> *mv->getRating();
        cin.ignore();
    } else if (mediaType == 2) {  // Music
        music* m = dynamic_cast<music*>(newMedia);
        cout << "Enter Artist: ";
        cin >> m->getArtist();
        cin.ignore();

        cout << "Enter Publisher: ";
        cin >> m->getPublisher();
        cin.ignore();

        cout << "Enter Duration: ";
        cin >> *m->getDuration();
        cin.ignore();
    } else if (mediaType == 3) {  // Video Game
        vgames* vg = dynamic_cast<vgames*>(newMedia);
        cout << "Enter Publisher: ";
        cin >> vg->getPublisher();
        cin.ignore();

        cout << "Enter Rating: ";
        cin >> *vg->getRating();
        cin.ignore();
    }

    // Add the media item to the storage vector
    storage.push_back(newMedia);
    cout << "Media item added successfully." << endl;
}

// Function to search for a media item by title
void searchMedia(const vector<dmedia*>& storage, const char* title) {
    cout << "Search Results:" << endl;

    for (size_t i = 0; i < storage.size(); ++i) {
        if (strcmp(storage[i]->getTitle(), title) == 0) {
            // Display information about the found media item
            cout << "Title: " << storage[i]->getTitle() << endl;
            cout << "Year: " << *storage[i]->getYear() << endl;
            cout << "Type: " << storage[i]->getType() << endl;

            // Additional details based on the type (you may need to extend this)
            if (storage[i]->getType() == 1) {  // Music
                music* m = dynamic_cast<music*>(storage[i]);
                cout << "Artist: " << m->getArtist() << endl;
                cout << "Publisher: " << m->getPublisher() << endl;
                cout << "Duration: " << *m->getDuration() << endl;
            } else if (storage[i]->getType() == 2) {  // Movie
                movies* mv = dynamic_cast<movies*>(storage[i]);
                cout << "Director: " << mv->getDirector() << endl;
                cout << "Duration: " << *mv->getDuration() << endl;
                cout << "Rating: " << *mv->getRating() << endl;
            } else if (storage[i]->getType() == 3) {  // Video Game
                vgames* vg = dynamic_cast<vgames*>(storage[i]);
                cout << "Publisher: " << vg->getPublisher() << endl;
                cout << "Rating: " << *vg->getRating() << endl;
            }

            cout << "------------------------" << endl;
        }
    }
}

// Function to delete a media item by title
void deleteMedia(vector<dmedia*>& storage, const char* title) {
    for (size_t i = 0; i < storage.size(); ++i) {
        if (strcmp(storage[i]->getTitle(), title) == 0) {
            // Display information about the media item to be deleted
            cout << "Deleting the following media item:" << endl;
            cout << "Title: " << storage[i]->getTitle() << endl;
            cout << "Year: " << *storage[i]->getYear() << endl;
            cout << "Type: " << storage[i]->getType() << endl;

            // Additional details based on the type (you may need to extend this)
            if (storage[i]->getType() == 1) {  // Music
                music* m = dynamic_cast<music*>(storage[i]);
                cout << "Artist: " << m->getArtist() << endl;
                cout << "Publisher: " << m->getPublisher() << endl;
                cout << "Duration: " << *m->getDuration() << endl;
            } else if (storage[i]->getType() == 2) {  // Movie
                movies* mv = dynamic_cast<movies*>(storage[i]);
                cout << "Director: " << mv->getDirector() << endl;
                cout << "Duration: " << *mv->getDuration() << endl;
                cout << "Rating: " << *mv->getRating() << endl;
            } else if (storage[i]->getType() == 3) {  // Video Game
                vgames* vg = dynamic_cast<vgames*>(storage[i]);
                cout << "Publisher: " << vg->getPublisher() << endl;
                cout << "Rating: " << *vg->getRating() << endl;
            }

            // Confirm deletion
            cout << "Are you sure you want to delete this item? (y/n): ";
            char confirmation;
            cin >> confirmation;

            if (confirmation == 'y' || confirmation == 'Y') {
                // Delete the item and remove it from the storage vector
                delete storage[i];
                storage.erase(storage.begin() + i);
                cout << "Item deleted successfully." << endl;
            
            } else {
                cout << "Deletion canceled." << endl;
            }

            return;  // Exit the function after deleting the item
        }
    }

    cout << "No matching media item found for deletion." << endl;
}

int main() {
    bool play = true;
    vector<dmedia*> storage;

    while (play == true) {
        char str[10];
        cout << "Input: ADD, SEARCH, DELETE, or QUIT: ";
        cin.get(str, 10);
        cin.ignore();

        if (strcmp(str, "ADD") == 0) {
            addMedia(storage);
        }
        else if (strcmp(str, "DELETE") == 0) {
            cout << "Enter the title to delete: ";
            char deleteTitle[30];
            cin >> deleteTitle;
            cin.ignore();
            deleteMedia(storage, deleteTitle);
        }
        else if (strcmp(str, "SEARCH") == 0) {
            cout << "Enter the title to search for: ";
            char searchTitle[30];
            cin >> searchTitle;
            cin.ignore();
            searchMedia(storage, searchTitle);
        }
        else if (strcmp(str, "QUIT") == 0) {
            play = false;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }

    // Cleanup: Delete dynamically allocated objects
    for (size_t i = 0; i < storage.size(); ++i) {
        delete storage[i];
    }

    return 0;
}

