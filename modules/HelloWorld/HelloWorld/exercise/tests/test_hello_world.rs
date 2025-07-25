#[cfg(test)]
mod tests {
    #[test]
    fn it_prints_hello_world() {
        use std::process::Command;

        let output = Command::new("cargo").arg("run").output().unwrap().stdout;

        assert_eq!(output, b"Hello World!\n".to_vec());
    }
}