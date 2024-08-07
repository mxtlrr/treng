// Internal: convert character to corresponding digit value
function covToDig(n, i){
  return n[i].charCodeAt(0) - '0'.charCodeAt(0);
}

// returns n + b
export const add = (n, b) => {
  if(typeof n != 'string' && typeof b != 'string'){
    n = n.toString();
    b = b.toString();
  }
  let result = ""; let carry = 0;

  // Pad the shorter string with leading zeros
  while (n.length < b.length) n = "0" + n;
  while (b.length < n.length) b = "0" + b;

  // Add digits from right to left
  for (let i = n.length - 1; i >= 0; i--) {
    let sum = covToDig(n,i) + covToDig(b,i) + carry;

    // Compute the new digit and carry
    let nd = sum % 10;
    carry = (sum-(nd))/10;  // Manual floor operation for carry

    // Convert the new digit back to a character and prepend it to the result
    result = String.fromCharCode(nd+'0'.charCodeAt(0)) + result;
  }

  // If there's a carry left, add it to the result
  if (carry > 0) {
    result = String.fromCharCode(carry + '0'.charCodeAt(0)) + result;
  }

  return result;
}

// unfortunately this is also required by tetration
export const sub = (n,b) => {
  // STUPID!
  if(typeof n != 'string' && typeof b != 'string'){
    n = n.toString();
    b = b.toString();
  }


  let res = "";
  let borrow = 0;

  // Pad the shorter string with leading zeros
  while (b.length < n.length) b = "0" + b;

  // Subtract digits from right to left
  for (let i = n.length - 1; i >= 0; i--) {
    let diff = covToDig(n,i) - covToDig(b,i) - borrow;

    if (diff < 0) {
      diff += 10; borrow = 1;
    } else borrow = 0;

    res = String.fromCharCode(diff + '0'.charCodeAt(0)) + res;
  }

  // Remove leading zeros
  while (res.length > 1 && res[0] === "0") {
      res = res.substring(1);
  }

  return res;
}

// returns n*b
export const mult = (n, b) => {
  let res = "0";
  for(let counter = "0"; counter != b; counter = add(counter,"1")) {
    res = add(res, n.toString());
  }
  return res;
}

export const exp = (n,b) => {
  let res = "1";
  for(let counter = "0"; counter != b; counter = add(counter, "1")){
    res = mult(res, n.toString());
  }
  return res;
}