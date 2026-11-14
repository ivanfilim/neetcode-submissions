class Twitter {
    final Map<Integer, Set<Integer>> usersMap = new HashMap<>();
    final Map<Integer, List<Tweet>> tweets = new HashMap<>();
    int counter = 0;
    
    public void postTweet(int userId, int tweetId) {
        tweets.computeIfAbsent(
            userId,
            k -> new ArrayList<>()
        ).addLast(new Tweet(counter--, tweetId));
    }
    
    public List<Integer> getNewsFeed(int userId) {
        final PriorityQueue<Integer> heap = new PriorityQueue<>();
        final Map<Integer, List<Integer>> m = new HashMap<>();
        usersMap.computeIfAbsent(
            userId,
            k -> new HashSet<>()
        ).add(userId);
        usersMap.get(userId).forEach(followeeId -> {
            List<Tweet> currTweets = tweets.get(followeeId);
            if (currTweets != null && !currTweets.isEmpty()) {
                Tweet tweet = currTweets.get(currTweets.size() - 1);
                int timestamp = tweet.timestamp();
                int tweetId = tweet.tweetId();
                heap.offer(timestamp);
                m.put(timestamp, List.of(followeeId, tweetId, currTweets.size() - 1));
            }
        });
        List<Integer> res = new ArrayList<>();
        while (!heap.isEmpty() && res.size() < 10) {
            int timestamp = heap.poll();
            List<Integer> data = m.get(timestamp);
            res.add(data.get(1));
            if (data.get(2) > 0) {
                int idx = data.get(2) - 1;
                List<Tweet> currTweets = tweets.get(data.get(0));
                m.put(
                    currTweets.get(idx).timestamp(),
                    List.of(
                        data.get(0),
                        currTweets.get(idx).tweetId(),
                        idx
                    )
                );
                heap.offer(currTweets.get(idx).timestamp());
            }
        }
        return res;
    }
    
    public void follow(int followerId, int followeeId) {
        usersMap.computeIfAbsent(
            followerId,
            k -> new HashSet<>()
        ).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        usersMap.computeIfAbsent(
            followerId,
            k -> new HashSet<>()
        ).remove(followeeId);
    }

    private static record Tweet(int timestamp, int tweetId) {}
}
