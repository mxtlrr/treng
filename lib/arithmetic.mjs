// returns n + b
export const add = (n, b) => {
  if(typeof n != 'string' && typeof b != 'string'){
    n = n.toString();
    b = b.toString();
  }
  let result = "";
  let carry = 0;
  
  // Pad digits so they're equal.
  while (n.length < b.length) n = "0" + n;
  while (b.length < n.length) b = "0" + b;

  // Add digits
  for (let i = n.length - 1; i >= 0; i--) {
    let sum = parseInt(n[i]) + parseInt(b[i]) + carry;
    result = (sum % 10) + result;
    carry = Math.floor(sum / 10);
  }
  
  // If there's a carry left, add it to the result
  if (carry > 0) result = carry + result;  
  return result;
}

// returns n*b
export const mult = (n, b) => {

}