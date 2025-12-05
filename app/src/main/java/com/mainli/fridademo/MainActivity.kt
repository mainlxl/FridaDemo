package com.mainli.fridademo

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.mainli.fridademo.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        binding.sampleText.text = md5("Mainli")
        binding.sampleText.setOnClickListener {
            binding.sampleText.text = stringFromJNI()
        }
    }

    external fun stringFromJNI(): String
    external fun md5(input: String): String

    companion object {
        init {
            System.loadLibrary("fridademo")
        }
    }
}