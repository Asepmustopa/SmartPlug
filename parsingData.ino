void parsing(String output[4], String myString)
{
  int ind1, ind2, ind3, ind4;
  ind1 = myString.indexOf('|');
  ind2 = myString.indexOf('|', ind1 + 1);
  ind3 = myString.indexOf('|', ind2 + 1);
  ind4 = myString.indexOf('|', ind3 + 1);
  output[1] = myString.substring(ind1 + 1, ind2);
  output[2] = myString.substring(ind2 + 1, ind3);
  output[3] = myString.substring(ind3 + 1, ind4);
}