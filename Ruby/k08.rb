require_relative 'executable'
require_relative 'k08_1sub'
require_relative 'k08_2sub'

class K08 < Executable
  def question1
    numbers = []
    (1..3).each do |x|
      print "#{x}つ目の値を入力してください。＞"
      numbers.append(gets.chomp.to_i)
    end

    puts 'どちらを調べますか？'
    print '（０：最大値　１：最小値）＞'
    choice = gets.chomp.to_i

    case choice
    when 0
      puts "#{numbers.count}の中で最大値は#{get_max_value(numbers[0], numbers[1], numbers[2])}です。"
    when 1
      puts "#{numbers.count}の中で最小値は#{get_min_value(numbers[0], numbers[1], numbers[2])}です。"
    end
  end

  def question2
    puts '冒険が今始まる！'
    playerHp = 200 + rand(0..100)
    continueGame = 1
    while continueGame != 0
      if playerHp == 0
        return
      end

      puts "あなたのHP：#{playerHp}"
      puts '奥に進みますか？（１：奥に進む　０．帰る）＞'
      continueGame = gets.chomp.to_i
      if continueGame == 1
        golemLv = rand(0..4)
        playerHp = attack_golem(golemLv, playerHp)
      end
    end
    puts 'リレ〇ト！'
  end
end
