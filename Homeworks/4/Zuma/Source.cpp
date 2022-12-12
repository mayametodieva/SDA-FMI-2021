#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

#define endl '\n'

long long finCount = 0;

void eraseBalls(list<long long>& balls, long long counter, list<long long>::iterator it) {
    list<long long>::iterator end;
    list<long long>::iterator start;
    list<long long>::iterator prev_start;
    list<long long>::iterator next_end;
    list<long long>::iterator it2 = it;

    if (balls.empty())
    {
        return;
    }

    if (next(it) != balls.end())
    {
        if (*it == *next(it))
        {
            while (it != balls.end() && *it == *next(it))
            {
                counter++;
                end = next(it);
                if (next(end) != balls.end())
                {
                    next_end = next(end);
                }
                else
                {
                    next_end = balls.end();
                }
                it++;
                if (next(it) == balls.end())
                    break;
            }
        }
        else
        {
            end = it;
            if (next(end) != balls.end())
            {
                next_end = next(end);
            }
            else
            {
                next_end = balls.end();
            }
        }
    }
    else
    {
        next_end = balls.end();
    }

    if (it2 != balls.begin())
    {
        if (*it2 == *prev(it2)) {
            while (it2 != balls.begin() && *it2 == *prev(it2))
            {
                counter++;
                start = prev(it2);

                if (start != balls.begin())
                {
                    prev_start = prev(start);
                }
                else
                {
                    prev_start = balls.begin();
                    break;
                }
                it2--;
            }
        }
        else
        {
            start = it2;
            if (start != balls.begin())
            {
                prev_start = prev(start);
            }
            else
            {
                prev_start = balls.begin();
            }
        }
    }
    else
    {
        prev_start = balls.begin();
    }


    if (counter >= 3)
    {
        finCount += counter;

        if (counter == balls.size())
        {
            balls.clear();
            printf("%lld\n", finCount);
            return;
        }
        else
        {
            balls.erase(start, next_end);


            if (balls.empty())
            {
                printf("%lld\n", finCount);

                return;
            }

            if (next_end == balls.end() || next_end == balls.begin())
            {
                printf("%lld\n", finCount);
            }
            else if (*prev_start == *next_end)
            {
                int curr_counter = 1;
                it = prev_start;
                eraseBalls(balls, curr_counter, it);
            }
            else {
                printf("%lld\n", finCount);
            }
            counter = 1;
        }
    }
    else
    {
        printf("%lld\n", finCount);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;

    cin >> N;

    list<long long> balls;

    vector<list<long long>::iterator> positions;

    for (long long i = 0; i < N; i++)
    {
        long long ball;

        cin >> ball;

        balls.push_back(ball);
        positions.push_back(prev(balls.end()));
    }

    long long Q;

    cin >> Q;

    vector<pair<long long, long long>> reqs(Q);

    for (long long i = 0; i < Q; i++)
    {
        cin >> reqs[i].first >> reqs[i].second;
    }

    for (long long i = 0; i < Q; i++) {

        if (balls.empty())
        {
            printf("Game Over\n");
        }
        else
        {
            finCount = 0;
            balls.insert(next(positions[reqs[i].first]), reqs[i].second);
            positions.push_back(next(positions[reqs[i].first]));

            int counter = 1;

            eraseBalls(balls, counter, next(positions[reqs[i].first]));
        }
    }

    if (balls.empty())
    {
        printf("-1");
    }
    else
    {
        for (list<long long>::iterator i = balls.begin(); i != balls.end(); i++)
            printf("%lld ", *i);
    }

    return 0;
}