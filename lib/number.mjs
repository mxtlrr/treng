export class Num {
  constructor(a, b){
    this.a = a;
    this.b = b;
  }

  // Generates a number via the method a*10^b
  Generate(){
    if(this.b != undefined){
      let f = `${this.a}`
      for(let a=0;a!=this.b;a++)f+='0';
      return f;
    }
    return this.a;
  }
}


export const ToSciNot = (n) => {
  if(typeof n != 'string') return '';
  return `${n[0]}*10^${n.length-1}`;
};