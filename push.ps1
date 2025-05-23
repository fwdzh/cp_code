$time = Get-Date -Format "yyyy-MM-dd HH:mm:ss"

if ($args.Count -eq 0) {
    $msg = "update on $time"
} else {
    $msg = "$($args -join ' ') $time"
}

git add .
git commit -m "$msg"
git push
git push gitee master
