# GitHub Repository Setup - Complete Instructions

## ⚠️ ERROR YOU GOT
```
fatal: repository 'https://github.com/neelgheewala-005/robotics-portfolio.git/' not found
```

**Why:** The repository doesn't exist on GitHub yet. You need to create it first.

---

## 🎯 What To Do Now

### Step 1: Create Repository on GitHub Website (5 minutes)

1. **Open your browser**
2. **Go to:** https://github.com/new
   - Or login to GitHub → Click **"+"** (top right) → **"New repository"**

3. **Fill out the form:**
   ```
   Repository name:     robotics-portfolio
   Description:         Robotics Engineering Portfolio
   Visibility:          PUBLIC ✓
   
   DO NOT CHECK:
   ☐ Initialize with README
   ☐ Add .gitignore
   ☐ Choose license
   ```

4. **Click:** Green **"Create repository"** button

5. **You'll see this screen:**
   - It will say: "...or push an existing repository from the command line"
   - It shows commands starting with: `git remote add origin...`

---

### Step 2: Copy Commands from GitHub (Very Important!)

After creating the repo, GitHub shows you a code box. You'll see something like:

```bash
git remote add origin https://github.com/neelgheewala-005/robotics-portfolio.git
git branch -M main
git push -u origin main
```

**⚠️ Copy EXACTLY what GitHub shows you**

---

### Step 3: Run Commands in Your Terminal

**Open Command Prompt and run:**

```bash
cd C:\Users\Prachi\Desktop\claude_project
```

Then run the commands GitHub gave you:

```bash
git remote add origin https://github.com/neelgheewala-005/robotics-portfolio.git
git branch -M main
git push -u origin main
```

---

## 🔐 If Git Asks for Authentication

You'll get a login prompt. On Windows, use one of these:

### Option 1: Personal Access Token (EASIEST)
1. Go to: https://github.com/settings/tokens/new
2. Click **"Generate new token (classic)"**
3. Name: `Portfolio Push`
4. Check the box: `repo`
5. Scroll down → **"Generate token"**
6. **Copy the token** (copy it now, you won't see it again!)
7. When Git asks for password: **Paste this token**

### Option 2: GitHub CLI Authentication
If you have `gh` installed:
```bash
gh auth login
```

---

## ✅ Success Signs

After running `git push -u origin main`, you should see:

```
Enumerating objects: 9, done.
Counting objects: 100% (9/9), done.
Delta compression using up to 8 threads
Compressing objects: 100% (7/7), done.
Writing objects: 100% (3.11 MiB | 1.55 MiB/s)
...
To https://github.com/neelgheewala-005/robotics-portfolio.git
 * [new branch]      main -> main
Branch 'main' set up to track remote branch 'main' from 'origin'.
```

✅ If you see this, you're done!

---

## 🌐 Enable GitHub Pages (Make Website Live)

After successful push:

1. Go to: https://github.com/neelgheewala-005/robotics-portfolio/settings/pages
2. Under "Build and deployment":
   - Source: **Deploy from a branch**
   - Branch: **main / (root)**
3. Click **Save**
4. Wait 1-2 minutes
5. Your website: https://neelgheewala-005.github.io/robotics-portfolio/

---

## 📋 Quick Checklist

- [ ] Created repository on GitHub website
- [ ] Repository name: `robotics-portfolio`
- [ ] Set to PUBLIC
- [ ] Did NOT initialize with README/gitignore
- [ ] Copied GitHub's commands
- [ ] Ran `git remote add origin...`
- [ ] Ran `git branch -M main`
- [ ] Ran `git push -u origin main`
- [ ] Authentication successful
- [ ] Enabled GitHub Pages in Settings

---

## 🆘 Troubleshooting

### "repository not found"
→ Create the repository first on GitHub

### "fatal: could not read Username"
→ Use Personal Access Token instead of password

### "remote origin already exists"
→ Run: `git remote remove origin` then start over

### "Permission denied"
→ Check authentication token is correct

---

## 📱 Once It's Live

Your portfolio will be at:
```
https://neelgheewala-005.github.io/robotics-portfolio/
```

You can:
- Download your CV
- View your projects
- See your code snippets
- Download KUKA files
- Share on LinkedIn/emails

---

## 💡 Important Notes

- Create repo on GitHub website FIRST
- Then run git commands from Command Prompt
- Use Personal Access Token for authentication
- Wait 1-2 minutes for GitHub Pages to activate

---

**Need help?** Run the commands and tell me what error you get, and I'll help fix it!
