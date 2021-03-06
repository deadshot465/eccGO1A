//
//  main.swift
//  SwiftProject
//
//  Created by 周哲輝 on 2019/05/05.
//  Copyright © 2019 周哲輝. All rights reserved.
//

import Foundation

func ShowSelections(chapter: Int) {
    if chapter < 10 {
        for i in 1...4 {
            print("\t\(i)) K0\(chapter)_\(i)")
        }
        if chapter == 9 {
            print("\t5) K0\(chapter)_5")
        }
    } else {
        let addedNumber = chapter >= 12 ? chapter + 3 : chapter
        for i in 1...4 {
            print("\t\(i)) K\(addedNumber)_\(i)")
        }
    }
}

var executables = [IDispatchable](arrayLiteral:
    K01(), K02(), K03(), K04(), K05(),
    K06(), K07(), K08(), K09(), K10(),
    K11(), K12(), FileControl())

print("実行したいプログラムを選択してください。")

for i in 1...executables.count {
    if i < 10 {
        print("\(i)) K0\(i)")
    }
    else {
        let addedNumber = i >= 12 ? i + 3 : i
        print("\(i)) K\(addedNumber)")
    }
}
print("100) Kex")
print("101) Kex_2")

if let choice = Int(readLine()!) {
    if choice == 100 {
        Kex.Execute()
    } else if choice == 101 {
        Kex_2.Execute()
    } else {
        ShowSelections(chapter: choice)
        let choice2 = Int(readLine()!)
        if choice != 9 {
            executables[choice - 1].Execute(num: choice2!)
        }
        else {
            (executables[8] as! K09).Execute(num: choice2!)
        }
    }
}
