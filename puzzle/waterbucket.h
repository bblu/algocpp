// bucket_state.h

const int BUCKETS_COUNT = 3;

struct Action
{
    int from;
    int to;
    int water;
};

struct BucketState
{
    int bucket_s[BUCKETS_COUNT];
    Action curAction;

    BucketState();
    BucketState(const int *buckets);
    BucketState(const BucketState& state);

    void setBuckets(const int *buckets);
    bool isBucketEmpty(int bucket);
    bool isSameState(const BucketState& state) const;
    bool canTakeDumpAction(int from, int to);

    void setAction(int water, int from, int to);
    bool dumpWater(int from, int to, BucketState &next);

    bool isFinalState();
    void printState();
};

