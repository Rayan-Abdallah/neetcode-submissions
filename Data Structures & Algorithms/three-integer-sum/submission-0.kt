class Solution {
    fun threeSum(nums: IntArray): List<List<Int>> {
        val negatives: List<Int> = nums.filter { it < 0 }.sorted()
        val positives: List<Int> = nums.filter { it > 0 }.sorted()
        val zeros: List<Int> = nums.filter { it == 0 }
        val visited: MutableSet<Pair<Int, Int>> = mutableSetOf()
        val ans: MutableList<List<Int>> = mutableListOf()
        if(zeros.size >= 3){
            ans.add(listOf(0, 0, 0))
        }
        fun checkPairs(lst: List<Int>, targetLst: List<Int>) {
            for(i in 0 until lst.size) {
                for(j in i+1 until lst.size){
                    if(visited.contains(Pair(lst[i], lst[j]))){
                        continue
                    }
                    val sum: Int = (lst[i] + lst[j])*-1
                    val index = targetLst.binarySearch(sum)
                    if(index >= 0){
                        ans.add(listOf(lst[i], lst[j], targetLst[index]))
                    }
                    visited.add(Pair(lst[i], lst[j]))
                }
            }
        }
        checkPairs(negatives, positives)
        checkPairs(positives, negatives)
        if(!zeros.isEmpty()){
            var prevValue: Int = 0
            for(i in 0 until negatives.size){
                if(negatives[i] == prevValue){
                    continue
                }
                val index = positives.binarySearch(negatives[i]*-1)
                if(index >= 0){
                    ans.add(listOf(negatives[i], 0, positives[index]))
                }
                prevValue = negatives[i]
            }
        }
        return ans.toList()
    }
}