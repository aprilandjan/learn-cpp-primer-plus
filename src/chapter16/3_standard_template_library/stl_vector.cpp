//
// Created by May on 2019/5/7.
//

#include "stl_vector.h"
#include <iostream>
#include <string>
#include <vector>
//  provide non-member function, like sort, for_each, etc.
#include <algorithm>

void use_stl_vector () {
    using std::vector;
    using std::cout;
    using std::cin;
    using std::string;

    const int NUM = 5;

    //  similar like typescript: var arr: Array<number>;
    vector<int> ratings(NUM);
    vector<string> titles(NUM);

    cout << "Do the following:\nEnter " << NUM << " book titles and your ratings(0-10).\n";

    int i;
    for(i = 0; i < NUM; i++) {
        cout << "Enter title #" << i + 1 << ":\n";
        getline(cin, titles[i]);
        cout << "Enter your ratings (0-10):\n";
        cin >> ratings[i];
        cin.get();
    }

    cout << "Done. You entered the following:\n";
    cout << "Rating\tBook\n";
    for(i = 0; i < NUM; i++) {
        cout << ratings[i] << "\t" << titles[i] << "\n";
    }
}

struct Review {
    std::string title;
    int rating;
};

//  fill a review object
bool fill_review(Review & r);
//  show review content
bool show_review(const Review & r);

bool operator<(const Review & r1, const Review & r2);

bool worseThan(const Review & r1, const Review & r2);

void vector_operations() {
    using std::vector;
    using std::cout;
    using std::cin;
    using std::string;

    vector<Review> books;
    Review temp;

    while (fill_review(temp)) {
        //  Array.push
        //  copy constructor?
        books.push_back(temp);
    }

    //  arr.length
    int num = books.size();
    if (num > 0) {
        cout << "You entered the following:\nRating\tBook\n";
        for(int i = 0; i < num; i++) {
            show_review(books[i]);
        }

        cout << "Re-prising:\nRating\tBook\n";

        // iterator: a pointer-like object
        // loop through vector
        vector<Review>::iterator pr;
        for(pr = books.begin(); pr != books.end(); pr++) {
            //  pointer de-reference
            show_review(*pr);
        }

        //  copy-constructor
        vector<Review> oldlist(books);
        if (num > 3) {
            //  Array.splice remove, [from, to)
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erasure:\n";
            for(pr = books.begin(); pr != books.end(); pr++) {
                show_review(*pr);
            }
            //  Array.concat insert.
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            cout << "After insertion:\n";
            for(pr = books.begin(); pr != books.end(); pr++) {
                show_review(*pr);
            }
        } else {
            cout << "Nothing entered, nothing gained.\n";
        }

        //  sort
        cout << "Sort by title:\nRating\tTitle\n";
        sort(oldlist.begin(), oldlist.end());
        for_each(oldlist.begin(), oldlist.end(), show_review);

        cout << "Sort by rating:\nRating\tTitle\n";
        sort(oldlist.begin(), oldlist.end(), worseThan);
        for_each(oldlist.begin(), oldlist.end(), show_review);

        //  shuffle
        cout << "Random shuffle:\nRating\tTitle\n";
        random_shuffle(oldlist.begin(), oldlist.end());
        for_each(oldlist.begin(), oldlist.end(), show_review);
    }

}

bool fill_review(Review & r) {
    std::cout << "\nEnter book title (q to quit): ";
    std::getline(std::cin, r.title);
    if (r.title == "q") {
        return false;
    }
    std::cout << "Enter book rating: ";
    std::cin >> r.rating;

    if (!std::cin) {
        return false;
    }
    //  get rid of rest of input line
    while(std::cin.get() != '\n') {
        continue;
    }
    return true;
}

bool show_review(const Review & r) {
    std::cout << r.rating << "\t" << r.title << "\n";
}

//  define r1 < r2 overloading
bool operator<(const Review & r1, const Review & r2) {
    if (r1.title < r2.title) {
        return true;
    } else if (r1.title == r2.title && r1.rating < r2.rating) {
        return true;
    }
    return false;
}

bool worseThan(const Review & r1, const Review & r2) {
    if (r1.rating < r2.rating) {
        return true;
    }
    return false;
}