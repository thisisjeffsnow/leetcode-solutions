typedef struct {
    int value;
    int position;
} HashNode;

static HashNode** node_table = NULL;
static int table_size = 0;

int *twoSum(int *nums, int numsSize, int target, int *returnSize){
    *returnSize = 2;
    int *returnValues = malloc((*returnSize)*sizeof(int));
    table_size = 2*numsSize;
    node_table = (HashNode**)(calloc(table_size, sizeof(HashNode)));
                              
    for(int i = 0; i < numsSize; i++) {
        unsigned int num = nums[i];
        unsigned int find = target - num;
        
        unsigned int idf = find % table_size;
        if(node_table[idf] != NULL && node_table[idf]->value == find) {
            returnValues[0] = i;
            returnValues[1] = node_table[idf]->position;
            for(int i = 0; i < table_size; i++) {
                if(node_table[i] != NULL) {
                    free(node_table[i]);
                }
            }
            free(node_table);
            return returnValues;
        }
        
        unsigned int idx = num % table_size;
        if(node_table[idx] != NULL) {
        }
        else {
            HashNode* node = NULL;
            node = (HashNode*)(malloc(sizeof(HashNode)));
            node->value = num;
            node->position = i;
            node_table[idx] = node;
        }
    }
                              
    return NULL;
    
}
