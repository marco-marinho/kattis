use std::io;
use io::stdin;
use io::stdout;
use std::io::Write;

fn to_votes(input: usize) -> String{
    let mut output = String::new();
    for i in [4, 2, 1] {
        if input & i > 0 {
            output += "Y";
        } else {
            output += "N";
        }
    }
    output += "\n";
    output
}

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Failed to read input");
    let n = input.trim().parse::<u32>().expect("Unable to parse n");
    input.clear();
    for _ in 0..n {
        stdin().read_line(&mut input).expect("Failed to read input");
        let m = input.trim().parse::<usize>().expect("Unable to parse m");
        input.clear();
        let mut voters = vec![vec![]; m];
        let mut dp = vec![vec![0; 8]; m];
        for i in 0..m {
            stdin().read_line(&mut input).expect("Failed to read input");
            voters[i] = input.trim().split(" ").map(|c| c.parse::<u32>().expect("Failed to parse priorities")).collect();
            input.clear();
        }
        for i in 0..8{
            if voters[m - 1][i ^ 1] < voters[m - 1][i ^ 2] && voters[m - 1][i ^ 1] < voters[m - 1][i ^ 4]{
                dp[m - 1][i] = i ^ 1;
            }
            else if voters[m - 1][i ^ 2] < voters[m - 1][i ^ 4]{
                dp[m - 1][i] = i ^ 2;
            }
            else {
                dp[m - 1][i] = i ^ 4;
            }
        }
        for j in (0..m-1).rev(){
            for i in 0..8 {
                if voters[j][dp[j + 1][i ^ 1]] < voters[j][dp[j + 1][i ^ 2]] && voters[j][dp[j + 1][i ^ 1]] < voters[j][dp[j + 1][i ^ 4]]{
                    dp[j][i] = dp[j + 1][i ^ 1];
                }
                else if voters[j][dp[j + 1][i ^ 2]] < voters[j][dp[j + 1][i ^ 4]]{
                    dp[j][i] = dp[j + 1][i ^ 2];
                }
                else {
                    dp[j][i] = dp[j + 1][i ^ 4];
                }
            }
        }
        stdout().write(to_votes(dp[0][0]).as_bytes()).unwrap();
    }
}

