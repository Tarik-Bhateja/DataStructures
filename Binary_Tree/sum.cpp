long int sumBT(Node* T)
{
    if (T == NULL) {
    return 0;
  }
 int sum = 0;
  sum += sumBT(T->left);
  sum += sumBT(T->right);
  if(T->key)
  {
     return sum + T->key; 
  }
  return 0;
}
