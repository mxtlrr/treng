import * as n from '../lib/number.mjs';
import * as a from '../lib/arithmetic.mjs';

const VERSION  = "0.0.1";
const TIMEDATE = `${new Date()}`;

// Returns a^^n
const tetration = (b, n1) => {
  // Base case.
  if (n1 === "0") {
      return "1";
  }

  // Otherwise, compute b^(b^(b^...(b^1)...))
  return a.exp(b, tetration(b, a.sub(n1, "1")));
}


console.log(`Welcome to Treng ${VERSION}.\nIt is ${TIMEDATE}`)
console.log("Calculating 2^^6...");

// Calculate 2^^4. Value should be 65536
let n4 = new n.Num(2).Generate();
let n5 = new n.Num(6).Generate();
console.log(n.ToSciNot(tetration(n4,n5)));