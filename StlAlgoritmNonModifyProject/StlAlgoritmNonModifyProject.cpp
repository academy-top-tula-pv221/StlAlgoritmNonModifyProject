#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class User
{
    string name;
    int age;
public:
    User(string name = "", int age = 0)
        : name{ name }, age{ age } {}

    string& Name(){ return name; }
    int& Age() { return age; }

    friend ostream& operator<<(ostream& out, const User& user)
    {
        out << "Name: " << user.name << ", age: " << user.age;
        return out;
    }

    friend bool operator==(const User& u1, const User& u2)
    {
        return u1.name == u2.name && u1.age == u2.age;
    }
};

int main()
{
    srand(time(nullptr));
    vector<User> users;
    users.push_back(User("Joe", 31));
    users.push_back(User("Bob", 27));
    users.push_back(User("Tim", 43));
    users.push_back(User("Tim", 29));
    users.push_back(User("Sam", 17));
    users.push_back(User("Tom", 22));

    vector<int> vrand;
    for (int i = 0; i < 10; i++)
        vrand.push_back(rand() % 100);

    // all_of, any_of, none_of, for_each
    /*
    vector<int> v1{ 1, 2, 3, 5, 7, 9, -2 };

    cout << boolalpha << all_of(v1.begin() + 2, v1.end(),
        [](auto item) { return item % 2; }) << "\n";

    cout << any_of(v1.begin() + 2, v1.end(),
        [](auto item) { return !(item % 2); }) << "\n";

    cout << none_of(v1.begin(), v1.end(),
        [](auto item) { return item < 0; }) << "\n";

    cout << any_of(users.begin(), users.end(), 
        [](auto item) { return item.Age() < 18; }) << "\n";

    for (auto item : v1)
        cout << item << " ";
    cout << "\n";

    for_each(v1.begin(), v1.end(), 
        [](auto item) 
        {
            cout << item << " ";
        });
    cout << "\n";
    */

    // count, count_if
    /*
    for (auto item : vrand) cout << item << " "; cout << "\n";

    cout << count(vrand.begin(), vrand.end(), 2) << "\n";
    cout << count_if(vrand.begin(), vrand.end(),
        [](auto item)
        {
            return item > 50;
        }) << "\n";
    */

    // mismatch
    /*
    vector<int> v3{ 1, 2, 3, 4, 5 };
    list<int> l1{ 1, 2, 3 };
    auto res1 = mismatch(v3.begin(), v3.end(), l1.begin(), l1.end());
    if (res1.first != v3.end())
        cout << "v3: " << *res1.first;
    else
        cout << "v3 end";

    if (res1.second != l1.end())
        cout << " - l1: " << *res1.second;
    else
        cout << " - l1 end";

    cout << "\n";
    */

    vector<int> v4{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    if (find(v4.begin(), v4.end(), 5) != v4.end())
        cout << *find(v4.begin(), v4.end(), 5) << "\n";
    else
        cout << "not found\n";
    
    auto it = find_if(v4.begin(), v4.end(),
        [](auto item) 
        { 
            return item > 5 && !(item % 2); 
        });
    cout << ((it != v4.end()) ? to_string(*it) : "not found") << "\n";
     
    vector<int> v5 { 1, 2, 3, 3, 4, 5, 6, 6, 3, 4, 7, 8, 3, 4, 8, 9 };
    list<int> l2{ 1, 2, 3, 4, 5, 6 };


    auto lb = ++++l2.begin();
    auto le = ----l2.end();
    //auto res2 = find_end(v5.begin(), v5.end(), lb, le);
    //auto res2 = find_first_of(v5.begin(), v5.end(), lb, le);
    //for_each(res2, v5.end(), [](auto item) { cout << item << " "; });
    cout << "\n";

    auto res3 = adjacent_find(v5.begin(), v5.end());
    for_each(res3, v5.end(), [](auto item) { cout << item << " "; });
    cout << "\n";

    auto res4 = adjacent_find(users.begin(), users.end(), 
        [](auto u1, auto u2) { return u1.Name() == u2.Name(); });
    for_each(res4, users.end(), [](auto item) { cout << item << "\n"; });
    cout << "\n";
}
