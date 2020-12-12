---
permalink: arbitrary_deep_recursive_output
code: I9WNY7
title: permalink.split("_")
usage:
  - https://leetcode.com/submissions/detail/361593754/?from=/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/

---
{% assign page.title = page.permalink | split: "_" | join: " " | capitalize %}
{% include_relative README.md %}
# Code
```cpp
{% include_relative {{ page.code }}.cpp %}
```

# [Ideone it!](https://ideone.com/{{ page.code }})

{% assign n = usage.size %}
{% if n > 0 %}
# Usage
{% for i in (1..n) %}
 - [Usage {{ i }}]({{usage[i-1]}})
{% endfor %}
{% endif %}
