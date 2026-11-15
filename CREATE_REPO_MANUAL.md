# Create GitHub Repository - Manual Steps

## Step-by-Step Guide to Create Your Repository

### Step 1: Go to GitHub New Repository Page
1. Open your browser
2. Go to: **https://github.com/new**
3. Or log in to GitHub, click **"+" in top right** → **"New repository"**

### Step 2: Fill in Repository Details
You'll see a form. Fill it like this:

```
Repository name: robotics-portfolio
Description: Robotics Engineering Portfolio - KUKA, Machine Vision, Embedded Systems
Visibility: PUBLIC (make sure this is selected)

☐ Initialize this repository with:
  ☐ Add a README file (UNCHECK - we already have one)
  ☐ Add .gitignore (UNCHECK - we already have one)
  ☐ Choose a license (leave unchecked)
```

### Step 3: Create Repository
- Click the green **"Create repository"** button
- You'll be taken to your new empty repository page

### Step 4: GitHub Will Show You Commands
After creating, GitHub shows you a section that says:

```
...or push an existing repository from the command line
```

Copy those exact commands (they'll look like what you see below)

---

## What to Do After Creating

GitHub will give you commands. They should look like:

```
git remote add origin https://github.com/neelgheewala-005/robotics-portfolio.git
git branch -M main
git push -u origin main
```

**IMPORTANT:** These are the commands you'll run. Let me help you with them below.

---

## The Commands to Run (In This Order)

Open Command Prompt/Terminal and run these exactly:

```bash
cd C:\Users\Prachi\Desktop\claude_project

git remote add origin https://github.com/neelgheewala-005/robotics-portfolio.git

git branch -M main

git push -u origin main
```

**Note:** The first time you push, you may need to authenticate. GitHub will guide you through that.

---

## If You Get Authentication Errors

On Windows, you might see a prompt asking for credentials. Options:

### Option A: Use Personal Access Token (Recommended)
1. Go to GitHub Settings: https://github.com/settings/tokens/new
2. Click "Generate new token" (classic)
3. Name it: "Portfolio Push"
4. Check: `repo` (full control of private repositories)
5. Scroll down, click "Generate token"
6. **Copy the token** (you'll only see it once)
7. When Git asks for password, paste this token instead

### Option B: Use SSH (More Advanced)
If you have SSH set up on your computer, you can use SSH URLs instead

---

## Troubleshooting

### Error: "repository not found"
**Cause:** Repository doesn't exist yet on GitHub
**Solution:** Create it first using steps above

### Error: "Authentication failed"
**Cause:** GitHub doesn't know who you are
**Solution:** Use Personal Access Token (Option A above)

### Error: "fatal: remote origin already exists"
**Cause:** You already added the remote
**Solution:** Run: `git remote remove origin` then try again

---

## After You Push Successfully

You'll see output like:
```
Enumerating objects: 9, done.
Counting objects: 100% (9/9), done.
Delta compression using up to 8 threads
Compressing objects: 100% (7/7), done.
Writing objects: 100% (9/9), 3.11 MiB
...
 * [new branch]      main -> main
Branch 'main' set up to track remote branch 'main' from 'origin'.
```

✅ That means it worked!

---

## Next: Enable GitHub Pages

Once your code is on GitHub:

1. Go to: https://github.com/neelgheewala-005/robotics-portfolio/settings/pages
2. Under "Build and deployment":
   - Source: **Deploy from a branch**
   - Branch: **main** / **(root)**
3. Click **Save**
4. Wait 1-2 minutes
5. Your site: **https://neelgheewala-005.github.io/robotics-portfolio/**

---

## Summary

1. ✅ Go to https://github.com/new
2. ✅ Create repo named "robotics-portfolio" (PUBLIC)
3. ✅ Run the git push commands
4. ✅ Enable GitHub Pages in Settings
5. ✅ Your portfolio goes live!

---

**Need help?** Let me know what error message you get and I can help troubleshoot!
