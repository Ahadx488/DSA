class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder ans = new StringBuilder(words.length);

        for (String word : words) {
            int wt = 0;

            for (int i = 0; i < word.length(); i++) {
                wt += weights[word.charAt(i) - 'a'];
            }

            ans.append((char) ('z' - (wt % 26)));
        }

        return ans.toString();
    }
}