mod adder;

fn main() {
    let x = 1;
    let y = 2;
    let result = adder::adder::add(x, y);

    println!("The sum of {0} and {1} is {2}", x, y, result)
}

