#[path = "../src/adder/adder.rs"]
mod adder;

use adder::add;

#[test]
fn it_adds_two_numbers() {
    assert_eq!(2, add(1, 1));
    assert_eq!(5, add(2, 3));
}
