import requests
import random

def get_problems():
    """获取所有题目数据"""
    url = "https://codeforces.com/api/problemset.problems"
    response = requests.get(url)
    if response.status_code == 200:
        return response.json()['result']['problems']
    else:
        print(f"Error: {response.status_code}")
        return []

def get_user_solved_problems(handles):
    """获取多个用户已经解决过的题目"""
    solved_problems = set()
    for handle in handles:
        url = f"https://codeforces.com/api/user.status?handle={handle.strip()}"
        response = requests.get(url)
        if response.status_code == 200:
            submissions = response.json()['result']
            for submission in submissions:
                if submission['verdict'] == 'OK':  # 只记录通过的题目
                    problem = submission['problem']
                    solved_problems.add((problem['contestId'], problem['index']))
        else:
            print(f"Error: 无法获取用户 {handle} 的提交记录，请检查用户名是否正确。")
    return solved_problems

def filter_problems_by_rating_range(problems, min_rating, max_rating):
    """根据难度范围过滤题目"""
    return [problem for problem in problems if 'rating' in problem and min_rating <= problem['rating'] <= max_rating]

def filter_unsolved_problems(problems, solved_problems):
    """过滤掉用户已经解决过的题目"""
    return [problem for problem in problems if (problem['contestId'], problem['index']) not in solved_problems]

def get_random_problems(problems, count):
    """随机选择指定数量的题目"""
    return random.sample(problems, min(count, len(problems)))

def validate_rating_range(min_rating, max_rating):
    """验证难度范围是否符合要求（800-3500，且是100的倍数）"""
    return (min_rating >= 800 and min_rating <= 3500 and min_rating % 100 == 0 and
            max_rating >= 800 and max_rating <= 3500 and max_rating % 100 == 0 and
            min_rating <= max_rating)

def main():
    problems = get_problems()
    if not problems:
        return

    # 用户输入
    handles_input = input("请输入Codeforces用户名（可选，多个用户名用逗号或空格分隔）：")
    handles = [handle.strip() for handle in handles_input.split(",")] if handles_input else []

    solved_problems = set()
    if handles:
        solved_problems = get_user_solved_problems(handles)

    while True:
        try:
            min_rating = int(input("请输入最小难度（800-3500，且是100的倍数）："))
            max_rating = int(input("请输入最大难度（800-3500，且是100的倍数）："))
            if validate_rating_range(min_rating, max_rating):
                break
            else:
                print("难度范围不符合要求，请重新输入！")
        except ValueError:
            print("请输入有效的数字！")

    count = int(input("请输入题目数量："))

    # 过滤题目并随机选择
    filtered_problems = filter_problems_by_rating_range(problems, min_rating, max_rating)
    if handles:
        filtered_problems = filter_unsolved_problems(filtered_problems, solved_problems)
    random_problems = get_random_problems(filtered_problems, count)

    # 输出结果
    print(f"\n随机选择的题目（难度 {min_rating}-{max_rating}）：")
    for problem in random_problems:
        contest_id = problem['contestId']
        index = problem['index']
        name = problem['name']
        problem_url = f"https://codeforces.com/problemset/problem/{contest_id}/{index}"
        print(f"{name} - {problem_url}")

if __name__ == "__main__":
    main()